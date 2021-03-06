# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#' Read contents of .gz file(s) into a single `character()`.
#' 
#' @template param-file_paths
#' @template return-character
#' @template author-bk
#'
#' @details If more than one file path is provided, each elemente of the returned vector contains the contents of a single file.
#' 
#' @export
#' 
read_gz_file <- function(file_paths) {
    .Call(`_fastgz_read_gz_file`, file_paths)
}

#' Read contents of .gz file(s) into a `character()`.
#' 
#' 
#' @template param-file_paths
#' @template return-character
#' @template author-bk
#' 
#' @export
#' 
#' 
read_gz_lines <- function(file_paths) {
    .Call(`_fastgz_read_gz_lines`, file_paths)
}

