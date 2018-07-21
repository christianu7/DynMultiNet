#include <math.h>
#include <Rmath.h>
#include <R.h>
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

#include "DynMultiNet_shared.h"

// [[Rcpp::interfaces(r, cpp)]]

// [[Rcpp::export]]
arma::mat sample_x_iht_mat_DynMultiNet_bin_cpp( arma::mat x_iht_mat,
                                                const arma::mat x_t_sigma_prior_inv,
                                                const arma::mat tau_h,
                                                const arma::cube y_ijt,
                                                const arma::cube w_ijt,
                                                const arma::cube s_ijt,
                                                const arma::mat mu_t ) {
  
  // Auxiliar objects
  unsigned int i=0;
  unsigned int j=0;
  unsigned int t=0;
  arma::cube aux_cube_1;
  arma::mat aux_mat_1;
  arma::mat aux_mat_2;
  arma::uvec aux_uvec_1;
  arma::uvec aux_uvec_2;
  arma::uvec aux_uvec_3;
  
  // Network and latent space dimensions
  unsigned int V_net = y_ijt.n_rows;
  unsigned int T_net = y_ijt.n_slices;
  unsigned int H_dim = x_iht_mat.n_cols / T_net;
  
  // Rcpp::Rcout << "V_net:" << V_net << std::endl ;
  // Rcpp::Rcout << "T_net:" << T_net << std::endl ;
  // Rcpp::Rcout << "H_dim:" << H_dim << std::endl ;
  
  arma::mat Y = arma::zeros<arma::mat>((V_net-1)*T_net,1);
  arma::mat W = arma::zeros<arma::mat>((V_net-1)*T_net,1);
  arma::mat S = arma::zeros<arma::mat>((V_net-1)*T_net,1);
  
  arma::mat C = arma::zeros<arma::mat>((V_net-1)*T_net,1);
  arma::mat Z = arma::zeros<arma::mat>((V_net-1)*T_net,1);
  
  arma::mat Omega((V_net-1)*T_net,(V_net-1)*T_net); Omega.eye();
  arma::sp_mat Omega_sp;
  
  arma::mat tau_h_diag(tau_h.n_rows,tau_h.n_rows); tau_h_diag.eye();
  tau_h_diag.diag() = tau_h;
  
  arma::mat x_i_cov_prior = kron( tau_h_diag, x_t_sigma_prior_inv );
  arma::mat x_i_cov_inv = arma::zeros<arma::mat>( T_net*H_dim, T_net*H_dim );
  arma::mat x_i_cov = arma::zeros<arma::mat>( T_net*H_dim, T_net*H_dim );
  
  arma::colvec aux_vec_mean = arma::zeros<arma::colvec>(T_net*H_dim);
  
  arma::mat X_all = arma::zeros<arma::mat>(V_net*T_net,T_net*H_dim);
  X_all = arma::zeros<arma::mat>(V_net*T_net,T_net*H_dim);
  aux_uvec_1 = T_net * arma::regspace<arma::uvec>( 0, V_net-1 );
  aux_uvec_2 = T_net * arma::regspace<arma::uvec>( 0, H_dim-1 );
  aux_uvec_3 = arma::regspace<arma::uvec>( 0, V_net-1 );
  for( t=0; t<T_net; t++ ) {
    X_all.submat( aux_uvec_1+t , aux_uvec_2+t ) = x_iht_mat.submat( aux_uvec_3, aux_uvec_2+t );
  }
  
  arma::mat X = arma::zeros<arma::mat>((V_net-1)*T_net,T_net*H_dim);
  arma::sp_mat X_sp;
  
  for( i=0; i<V_net; i++ ) {
    // i=3;
    
    aux_mat_1 = y_ijt.subcube(i,0,0, i,i,T_net-1);
    aux_mat_2 = y_ijt.subcube(i,i,0, V_net-1,i,T_net-1);
    Y = join_vert(aux_mat_1,aux_mat_2);
    Y.shed_rows(i,i+1);
    Y = Y.t();
    Y.reshape((V_net-1)*T_net,1);
    
    aux_mat_1 = w_ijt.subcube(i,0,0, i,i,T_net-1);
    aux_mat_2 = w_ijt.subcube(i,i,0, V_net-1,i,T_net-1);
    W = join_vert(aux_mat_1,aux_mat_2);
    W.shed_rows(i,i+1);
    W = W.t();
    W.reshape((V_net-1)*T_net,1);
    
    Omega.diag() = W;
    
    aux_mat_1 = s_ijt.subcube(i,0,0, i,i,T_net-1);
    aux_mat_2 = s_ijt.subcube(i,i,0, V_net-1,i,T_net-1);
    S = join_vert(aux_mat_1,aux_mat_2);
    S.shed_rows(i,i+1);
    S = S.t();
    S.reshape((V_net-1)*T_net,1);
    
    // X
    X = X_all;
    X.shed_rows(T_net*i,T_net*(i+1)-1);
    
    X_sp = arma::sp_mat(X);
    Omega_sp = arma::sp_mat(Omega);
    
    x_i_cov_inv = X_sp.t() * Omega_sp * X_sp + x_i_cov_prior;
    // x_i_cov_inv = X.t() * Omega * X + x_i_cov_prior ;
    
    x_i_cov = arma::inv_sympd(x_i_cov_inv);
    
    C = S - X_sp * trans(x_iht_mat.row(i));
    Z = (Y-0.5)/W - C;
    
    aux_vec_mean = X_sp.t() * Omega_sp * Z;
    
    x_iht_mat.row(i) = trans(arma::mvnrnd( x_i_cov*aux_vec_mean , x_i_cov ));
  }
  
  return x_iht_mat;
}



// [[Rcpp::export]]
arma::mat sample_mu_t_DynMultiNet_bin_cpp( arma::colvec mu_t,
                                           const arma::mat mu_t_cov_prior_inv,
                                           const arma::cube y_ijt,
                                           const arma::cube w_ijt,
                                           const arma::cube s_ijt ) {
  // Auxiliar objects
  unsigned int i=0;
  arma::cube aux_cube_1;
  arma::mat aux_mat_1;
  arma::mat aux_mat_2;
  arma::uvec aux_uvec_1;
  arma::uvec aux_uvec_2;
  arma::uvec aux_uvec_3;
  
  // Network and latent space dimensions
  unsigned int V_net = y_ijt.n_rows;
  unsigned int T_net = y_ijt.n_slices;
  
  arma::colvec Y = arma::zeros<arma::colvec>(1);
  arma::colvec W = arma::zeros<arma::colvec>(1);
  arma::colvec S = arma::zeros<arma::colvec>(1);
  
  arma::colvec C = arma::zeros<arma::colvec>(1);
  arma::colvec Z = arma::zeros<arma::colvec>(1);
  
  aux_mat_1 = arma::ones<arma::mat>(V_net*(V_net-1)/2,1);
  aux_mat_2 = arma::zeros<arma::mat>(T_net,T_net); aux_mat_2.eye();
  arma::mat X = arma::kron( aux_mat_1, aux_mat_2 );
  arma::sp_mat X_sp = arma::sp_mat(X);
  
  arma::mat Omega = arma::zeros<arma::mat>(T_net*V_net*(V_net-1)/2,T_net*V_net*(V_net-1)/2); Omega.eye();
  arma::sp_mat Omega_sp = arma::sp_mat(Omega);
  
  arma::mat mu_t_cov_inv;
  arma::mat mu_t_cov;
  arma::colvec aux_vec_mean = arma::zeros<arma::colvec>(T_net);
  
  for( i=1; i<V_net; i++ ) {
    aux_mat_1 = y_ijt.subcube(i,0,0, i,i-1,T_net-1);
    aux_mat_1 = aux_mat_1.t();
    aux_mat_1.reshape(i*T_net,1);
    Y.insert_rows( Y.n_rows, aux_mat_1);
    
    aux_mat_1 = w_ijt.subcube(i,0,0, i,i-1,T_net-1);
    aux_mat_1 = aux_mat_1.t();
    aux_mat_1.reshape(i*T_net,1);
    W.insert_rows( W.n_rows, aux_mat_1);
    
    aux_mat_1 = s_ijt.subcube(i,0,0, i,i-1,T_net-1);
    aux_mat_1 = aux_mat_1.t();
    aux_mat_1.reshape(i*T_net,1);
    S.insert_rows( S.n_rows, aux_mat_1);
  }
  Y.shed_row(0); W.shed_row(0); S.shed_row(0);
  Omega_sp.diag() = W;
  
  mu_t_cov_inv = X_sp.t() * Omega_sp * X_sp + mu_t_cov_prior_inv;
  // x_i_cov_inv = X.t() * Omega * X + x_i_cov_prior ;
  
  mu_t_cov = arma::inv_sympd(mu_t_cov_inv);
  
  C = S - X_sp * mu_t;
  Z = (Y-0.5)/W - C;
  
  aux_vec_mean = X_sp.t() * Omega_sp * Z;
  
  mu_t = arma::mvnrnd( mu_t_cov*aux_vec_mean , mu_t_cov );
  
  return mu_t;
}
