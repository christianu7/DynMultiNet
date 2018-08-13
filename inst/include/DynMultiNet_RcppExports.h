// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_DynMultiNet_RCPPEXPORTS_H_GEN_
#define RCPP_DynMultiNet_RCPPEXPORTS_H_GEN_

#include <RcppArmadillo.h>
#include <Rcpp.h>

namespace DynMultiNet {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("DynMultiNet", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("DynMultiNet", "_DynMultiNet_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in DynMultiNet");
            }
        }
    }

    inline arma::mat sample_mu_t_DynMultiNet_bin_cpp(arma::colvec mu_t, const arma::mat mu_t_cov_prior_inv, const arma::cube y_ijt, const arma::cube w_ijt, const arma::cube s_ijt, const bool directed = false, bool check_Y = false) {
        typedef SEXP(*Ptr_sample_mu_t_DynMultiNet_bin_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_sample_mu_t_DynMultiNet_bin_cpp p_sample_mu_t_DynMultiNet_bin_cpp = NULL;
        if (p_sample_mu_t_DynMultiNet_bin_cpp == NULL) {
            validateSignature("arma::mat(*sample_mu_t_DynMultiNet_bin_cpp)(arma::colvec,const arma::mat,const arma::cube,const arma::cube,const arma::cube,const bool,bool)");
            p_sample_mu_t_DynMultiNet_bin_cpp = (Ptr_sample_mu_t_DynMultiNet_bin_cpp)R_GetCCallable("DynMultiNet", "_DynMultiNet_sample_mu_t_DynMultiNet_bin_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_sample_mu_t_DynMultiNet_bin_cpp(Shield<SEXP>(Rcpp::wrap(mu_t)), Shield<SEXP>(Rcpp::wrap(mu_t_cov_prior_inv)), Shield<SEXP>(Rcpp::wrap(y_ijt)), Shield<SEXP>(Rcpp::wrap(w_ijt)), Shield<SEXP>(Rcpp::wrap(s_ijt)), Shield<SEXP>(Rcpp::wrap(directed)), Shield<SEXP>(Rcpp::wrap(check_Y)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<arma::mat >(rcpp_result_gen);
    }

    inline arma::mat sample_beta_z_layer_DynMultiNet_bin_cpp(arma::colvec beta_t, arma::colvec z_t, const arma::mat beta_t_cov_prior_inv, const arma::cube y_ijt, const arma::cube w_ijt, const arma::cube s_ijt, const bool directed = false, bool check_Y = false) {
        typedef SEXP(*Ptr_sample_beta_z_layer_DynMultiNet_bin_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_sample_beta_z_layer_DynMultiNet_bin_cpp p_sample_beta_z_layer_DynMultiNet_bin_cpp = NULL;
        if (p_sample_beta_z_layer_DynMultiNet_bin_cpp == NULL) {
            validateSignature("arma::mat(*sample_beta_z_layer_DynMultiNet_bin_cpp)(arma::colvec,arma::colvec,const arma::mat,const arma::cube,const arma::cube,const arma::cube,const bool,bool)");
            p_sample_beta_z_layer_DynMultiNet_bin_cpp = (Ptr_sample_beta_z_layer_DynMultiNet_bin_cpp)R_GetCCallable("DynMultiNet", "_DynMultiNet_sample_beta_z_layer_DynMultiNet_bin_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_sample_beta_z_layer_DynMultiNet_bin_cpp(Shield<SEXP>(Rcpp::wrap(beta_t)), Shield<SEXP>(Rcpp::wrap(z_t)), Shield<SEXP>(Rcpp::wrap(beta_t_cov_prior_inv)), Shield<SEXP>(Rcpp::wrap(y_ijt)), Shield<SEXP>(Rcpp::wrap(w_ijt)), Shield<SEXP>(Rcpp::wrap(s_ijt)), Shield<SEXP>(Rcpp::wrap(directed)), Shield<SEXP>(Rcpp::wrap(check_Y)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<arma::mat >(rcpp_result_gen);
    }

    inline arma::cube sample_x_ith_DynMultiNet_bin_cpp(arma::cube x_ith, const arma::mat x_t_sigma_prior_inv, const arma::colvec tau_h, const arma::cube y_ijt, const arma::cube w_ijt, const arma::cube s_ijt, bool check_Y = false) {
        typedef SEXP(*Ptr_sample_x_ith_DynMultiNet_bin_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_sample_x_ith_DynMultiNet_bin_cpp p_sample_x_ith_DynMultiNet_bin_cpp = NULL;
        if (p_sample_x_ith_DynMultiNet_bin_cpp == NULL) {
            validateSignature("arma::cube(*sample_x_ith_DynMultiNet_bin_cpp)(arma::cube,const arma::mat,const arma::colvec,const arma::cube,const arma::cube,const arma::cube,bool)");
            p_sample_x_ith_DynMultiNet_bin_cpp = (Ptr_sample_x_ith_DynMultiNet_bin_cpp)R_GetCCallable("DynMultiNet", "_DynMultiNet_sample_x_ith_DynMultiNet_bin_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_sample_x_ith_DynMultiNet_bin_cpp(Shield<SEXP>(Rcpp::wrap(x_ith)), Shield<SEXP>(Rcpp::wrap(x_t_sigma_prior_inv)), Shield<SEXP>(Rcpp::wrap(tau_h)), Shield<SEXP>(Rcpp::wrap(y_ijt)), Shield<SEXP>(Rcpp::wrap(w_ijt)), Shield<SEXP>(Rcpp::wrap(s_ijt)), Shield<SEXP>(Rcpp::wrap(check_Y)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<arma::cube >(rcpp_result_gen);
    }

    inline arma::cube sample_x_ith_shared_DynMultiNet_bin_cpp(arma::cube x_ith_shared, const arma::mat x_t_sigma_prior_inv, const arma::colvec tau_h, const arma::field<arma::cube> y_ijtk, const arma::field<arma::cube> w_ijtk, const arma::field<arma::cube> s_ijtk, bool check_Y = false) {
        typedef SEXP(*Ptr_sample_x_ith_shared_DynMultiNet_bin_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_sample_x_ith_shared_DynMultiNet_bin_cpp p_sample_x_ith_shared_DynMultiNet_bin_cpp = NULL;
        if (p_sample_x_ith_shared_DynMultiNet_bin_cpp == NULL) {
            validateSignature("arma::cube(*sample_x_ith_shared_DynMultiNet_bin_cpp)(arma::cube,const arma::mat,const arma::colvec,const arma::field<arma::cube>,const arma::field<arma::cube>,const arma::field<arma::cube>,bool)");
            p_sample_x_ith_shared_DynMultiNet_bin_cpp = (Ptr_sample_x_ith_shared_DynMultiNet_bin_cpp)R_GetCCallable("DynMultiNet", "_DynMultiNet_sample_x_ith_shared_DynMultiNet_bin_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_sample_x_ith_shared_DynMultiNet_bin_cpp(Shield<SEXP>(Rcpp::wrap(x_ith_shared)), Shield<SEXP>(Rcpp::wrap(x_t_sigma_prior_inv)), Shield<SEXP>(Rcpp::wrap(tau_h)), Shield<SEXP>(Rcpp::wrap(y_ijtk)), Shield<SEXP>(Rcpp::wrap(w_ijtk)), Shield<SEXP>(Rcpp::wrap(s_ijtk)), Shield<SEXP>(Rcpp::wrap(check_Y)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<arma::cube >(rcpp_result_gen);
    }

    inline Rcpp::List sample_x_ith_DynMultiNet_bin_dir_cpp(arma::cube x_ith_send, arma::cube x_ith_receive, const arma::mat x_t_sigma_prior_inv, const arma::colvec tau_h_send, const arma::colvec tau_h_receive, const arma::cube y_ijt, const arma::cube w_ijt, const arma::cube s_ijt, bool check_Y = false) {
        typedef SEXP(*Ptr_sample_x_ith_DynMultiNet_bin_dir_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_sample_x_ith_DynMultiNet_bin_dir_cpp p_sample_x_ith_DynMultiNet_bin_dir_cpp = NULL;
        if (p_sample_x_ith_DynMultiNet_bin_dir_cpp == NULL) {
            validateSignature("Rcpp::List(*sample_x_ith_DynMultiNet_bin_dir_cpp)(arma::cube,arma::cube,const arma::mat,const arma::colvec,const arma::colvec,const arma::cube,const arma::cube,const arma::cube,bool)");
            p_sample_x_ith_DynMultiNet_bin_dir_cpp = (Ptr_sample_x_ith_DynMultiNet_bin_dir_cpp)R_GetCCallable("DynMultiNet", "_DynMultiNet_sample_x_ith_DynMultiNet_bin_dir_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_sample_x_ith_DynMultiNet_bin_dir_cpp(Shield<SEXP>(Rcpp::wrap(x_ith_send)), Shield<SEXP>(Rcpp::wrap(x_ith_receive)), Shield<SEXP>(Rcpp::wrap(x_t_sigma_prior_inv)), Shield<SEXP>(Rcpp::wrap(tau_h_send)), Shield<SEXP>(Rcpp::wrap(tau_h_receive)), Shield<SEXP>(Rcpp::wrap(y_ijt)), Shield<SEXP>(Rcpp::wrap(w_ijt)), Shield<SEXP>(Rcpp::wrap(s_ijt)), Shield<SEXP>(Rcpp::wrap(check_Y)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::List >(rcpp_result_gen);
    }

    inline Rcpp::List sample_x_ith_shared_DynMultiNet_bin_dir_cpp(arma::cube x_ith_shared_send, arma::cube x_ith_shared_receive, const arma::mat x_t_sigma_prior_inv, const arma::colvec tau_h_shared_send, const arma::colvec tau_h_shared_receive, const arma::field<arma::cube> y_ijtk, const arma::field<arma::cube> w_ijtk, const arma::field<arma::cube> s_ijtk, bool check_Y = false) {
        typedef SEXP(*Ptr_sample_x_ith_shared_DynMultiNet_bin_dir_cpp)(SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP,SEXP);
        static Ptr_sample_x_ith_shared_DynMultiNet_bin_dir_cpp p_sample_x_ith_shared_DynMultiNet_bin_dir_cpp = NULL;
        if (p_sample_x_ith_shared_DynMultiNet_bin_dir_cpp == NULL) {
            validateSignature("Rcpp::List(*sample_x_ith_shared_DynMultiNet_bin_dir_cpp)(arma::cube,arma::cube,const arma::mat,const arma::colvec,const arma::colvec,const arma::field<arma::cube>,const arma::field<arma::cube>,const arma::field<arma::cube>,bool)");
            p_sample_x_ith_shared_DynMultiNet_bin_dir_cpp = (Ptr_sample_x_ith_shared_DynMultiNet_bin_dir_cpp)R_GetCCallable("DynMultiNet", "_DynMultiNet_sample_x_ith_shared_DynMultiNet_bin_dir_cpp");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_sample_x_ith_shared_DynMultiNet_bin_dir_cpp(Shield<SEXP>(Rcpp::wrap(x_ith_shared_send)), Shield<SEXP>(Rcpp::wrap(x_ith_shared_receive)), Shield<SEXP>(Rcpp::wrap(x_t_sigma_prior_inv)), Shield<SEXP>(Rcpp::wrap(tau_h_shared_send)), Shield<SEXP>(Rcpp::wrap(tau_h_shared_receive)), Shield<SEXP>(Rcpp::wrap(y_ijtk)), Shield<SEXP>(Rcpp::wrap(w_ijtk)), Shield<SEXP>(Rcpp::wrap(s_ijtk)), Shield<SEXP>(Rcpp::wrap(check_Y)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::List >(rcpp_result_gen);
    }

}

#endif // RCPP_DynMultiNet_RCPPEXPORTS_H_GEN_
