// Copyright (C) 2019 Brendan Knapp
// This file is part of fastread.
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Rcpp.h>

#include <fstream>
#include "gzstream.h"

//' Read contents of .gz file(s) into a single `character()`.
//' 
//' @template param-file_paths
//' @template return-character
//' @template author-bk
//'
//' @details If more than one file path is provided, each element of the returned vector contains the contents of a single file.
//' 
//' @export
//' 
// [[Rcpp::export]]
std::vector<std::string> read_gz_file(const Rcpp::CharacterVector& file_paths) {
  std::vector<std::string> out;

  for (const auto& v : file_paths) {
    igzstream in_file;
    in_file.open(v);

    const std::string content( std::istreambuf_iterator<char>{in_file},
                               std::istreambuf_iterator<char>() );
    out.push_back(content);

    in_file.close();
  }

  return out;
}


//' Read contents of .gz file(s) into a `character()`.
//' 
//' 
//' @template param-file_paths
//' @template return-character
//' @template author-bk
//' 
//' @export
//' 
//' 
// [[Rcpp::export]]
std::vector<std::string> read_gz_lines(const Rcpp::CharacterVector& file_paths) {
  std::vector<std::string> out;

  for (const auto& v : file_paths) {
    igzstream in_file;
    in_file.open(v);

    std::string line_string;
    while ( std::getline(in_file, line_string) ) {
      out.push_back(line_string);
    }

    in_file.close();
  }

  return out;
}


/*** R
*/
