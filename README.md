# Optimisation


C++20

# C++20 Optimization Library

## Overview

This project is a modern C++20 library focused on implementing and optimizing mathematical and numerical methods for computational efficiency. The goal is to explore, implement, and document different methods for solving optimization problems.

The first implementation in this library is the **Householder transformation**, a fundamental linear algebra operation often used in QR decompositions. Future enhancements will focus on integrating **parallel programming techniques**, including **SIMD (Single Instruction, Multiple Data)** and optimized pointer arithmetic, to achieve superior performance.

## Features

- **Householder Transformation**:
  - Efficient computation of Householder matrices.
  - Implementation based on modern C++20 standards.
  - Asserts for validating functionality.
  
- **C++20 Modern Features**:
  - Utilization of `std::array`, templates, and concepts for strong type safety.
  - Compatibility with the latest C++ standards.

- **Planned Enhancements**:
  - Parallel programming techniques, including:
    - SIMD for vectorized computations.
    - Pointer optimizations for memory efficiency.
  - Comprehensive benchmarking framework for performance evaluation.
  - Additional optimization techniques.

## Getting Started

### Requirements

- **Compiler**: A C++20-compliant compiler such as:
  - GCC 10+ 
  - Clang 10+
  - MSVC 2019 (v16.11) or later
- **Build System**: CMake 3.20 or later.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/JulieDornat/Optimisation.git
