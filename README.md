# Footprint Collision Checker

C++ footprint (2D polygon outline) collision checker:
- extracted from [ROS2 navigation2](https://github.com/ros-planning/navigation2/tree/cfa284334f4e76760354aae485b4b7d2c57a5c97) stack
- with refactored out ROS2 dependencies (replaced with template parameters)

This is header only library.

## State

- interface subject to change

## Template Requirements

See example for now.

## Building Instructions

This is header only library (just include in your code).

To build example:

```bash
git clone https://github.com/bmegli/footprint-collision-checker.git
cd footprint-collision-checker
mkdir build
cd build
cmake ..
make
```

## Running Examples

```bash
./simple_example
```

## Using

See example for now.

