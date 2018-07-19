// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/DynMultiNet.h"
#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

// sample_x_iht_mat_DynMultiNet_bin_cpp
arma::mat sample_x_iht_mat_DynMultiNet_bin_cpp(arma::mat x_iht_mat, const arma::mat x_t_sigma_prior_inv, const arma::mat tau_h, const arma::cube y_ijt, const arma::cube w_ijt, const arma::cube s_ijt, const arma::mat mu_t);
static SEXP _DynMultiNet_sample_x_iht_mat_DynMultiNet_bin_cpp_try(SEXP x_iht_matSEXP, SEXP x_t_sigma_prior_invSEXP, SEXP tau_hSEXP, SEXP y_ijtSEXP, SEXP w_ijtSEXP, SEXP s_ijtSEXP, SEXP mu_tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x_iht_mat(x_iht_matSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type x_t_sigma_prior_inv(x_t_sigma_prior_invSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type tau_h(tau_hSEXP);
    Rcpp::traits::input_parameter< const arma::cube >::type y_ijt(y_ijtSEXP);
    Rcpp::traits::input_parameter< const arma::cube >::type w_ijt(w_ijtSEXP);
    Rcpp::traits::input_parameter< const arma::cube >::type s_ijt(s_ijtSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type mu_t(mu_tSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_x_iht_mat_DynMultiNet_bin_cpp(x_iht_mat, x_t_sigma_prior_inv, tau_h, y_ijt, w_ijt, s_ijt, mu_t));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _DynMultiNet_sample_x_iht_mat_DynMultiNet_bin_cpp(SEXP x_iht_matSEXP, SEXP x_t_sigma_prior_invSEXP, SEXP tau_hSEXP, SEXP y_ijtSEXP, SEXP w_ijtSEXP, SEXP s_ijtSEXP, SEXP mu_tSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_DynMultiNet_sample_x_iht_mat_DynMultiNet_bin_cpp_try(x_iht_matSEXP, x_t_sigma_prior_invSEXP, tau_hSEXP, y_ijtSEXP, w_ijtSEXP, s_ijtSEXP, mu_tSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// rcpparma_hello_world
arma::mat rcpparma_hello_world();
RcppExport SEXP _DynMultiNet_rcpparma_hello_world() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpparma_hello_world());
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_outerproduct
arma::mat rcpparma_outerproduct(const arma::colvec& x);
RcppExport SEXP _DynMultiNet_rcpparma_outerproduct(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_outerproduct(x));
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_innerproduct
double rcpparma_innerproduct(const arma::colvec& x);
RcppExport SEXP _DynMultiNet_rcpparma_innerproduct(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_innerproduct(x));
    return rcpp_result_gen;
END_RCPP
}
// rcpparma_bothproducts
Rcpp::List rcpparma_bothproducts(const arma::colvec& x);
RcppExport SEXP _DynMultiNet_rcpparma_bothproducts(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::colvec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpparma_bothproducts(x));
    return rcpp_result_gen;
END_RCPP
}

// validate (ensure exported C++ functions exist before calling them)
static int _DynMultiNet_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("arma::mat(*sample_x_iht_mat_DynMultiNet_bin_cpp)(arma::mat,const arma::mat,const arma::mat,const arma::cube,const arma::cube,const arma::cube,const arma::mat)");
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP _DynMultiNet_RcppExport_registerCCallable() { 
    R_RegisterCCallable("DynMultiNet", "_DynMultiNet_sample_x_iht_mat_DynMultiNet_bin_cpp", (DL_FUNC)_DynMultiNet_sample_x_iht_mat_DynMultiNet_bin_cpp_try);
    R_RegisterCCallable("DynMultiNet", "_DynMultiNet_RcppExport_validate", (DL_FUNC)_DynMultiNet_RcppExport_validate);
    return R_NilValue;
}

static const R_CallMethodDef CallEntries[] = {
    {"_DynMultiNet_sample_x_iht_mat_DynMultiNet_bin_cpp", (DL_FUNC) &_DynMultiNet_sample_x_iht_mat_DynMultiNet_bin_cpp, 7},
    {"_DynMultiNet_rcpparma_hello_world", (DL_FUNC) &_DynMultiNet_rcpparma_hello_world, 0},
    {"_DynMultiNet_rcpparma_outerproduct", (DL_FUNC) &_DynMultiNet_rcpparma_outerproduct, 1},
    {"_DynMultiNet_rcpparma_innerproduct", (DL_FUNC) &_DynMultiNet_rcpparma_innerproduct, 1},
    {"_DynMultiNet_rcpparma_bothproducts", (DL_FUNC) &_DynMultiNet_rcpparma_bothproducts, 1},
    {"_DynMultiNet_RcppExport_registerCCallable", (DL_FUNC) &_DynMultiNet_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_DynMultiNet(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
