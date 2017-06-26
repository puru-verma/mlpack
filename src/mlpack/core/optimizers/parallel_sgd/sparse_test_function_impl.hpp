/**
 * @file sparse_test_function.hpp
 * @author Shikhar Bhardwaj
 *
 * Sparse test function for Parallel SGD.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_CORE_OPTIMIZERS_PARALLEL_SGD_SPARSE_TEST_FUNCTION_IMPL_HPP
#define MLPACK_CORE_OPTIMIZERS_PARALLEL_SGD_SPARSE_TEST_FUNCTION_IMPL_HPP

// In case it hasn't been included yet.
#include "sparse_test_function.hpp"

namespace mlpack {
namespace optimization {
namespace test {

//! Evaluate a function.
double SparseTestFunction::Evaluate(
    const arma::mat& coordinates, const size_t i) const
{
  return coordinates[i] * coordinates[i] + bi[i] * coordinates[i] +
    intercepts[i];
}

  //! Evaluate the gradient of a function.
void SparseTestFunction::Gradient(const arma::mat& coordinates,
    const size_t i,
    arma::mat& gradient) const
{
  gradient = arma::vec(coordinates.n_rows, 1, arma::fill::zeros);
  gradient[i] = 2 * coordinates[i] + bi[i];
}

arma::Col<size_t> SparseTestFunction::Components(size_t id)
{
  return arma::Col<size_t>({ id });
}

} // namespace test
} // namespace optimization
} // namespace mlpack

#endif
