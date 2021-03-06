#include "reeds_shepp.h"
#include "wrapper.h"


void* rsspace_create(double r)
{
  auto ptr = static_cast<void*>(new ReedsSheppStateSpace(r));
  return ptr;
}

void rsspace_delete(void* ptr_space){
  auto space = static_cast<ReedsSheppStateSpace*>(ptr_space);
  free(space);
}

double rsspace_radius(void* ptr_space)
{
  auto space = static_cast<ReedsSheppStateSpace*>(ptr_space);
  return space->rho_;
}

// deplicated
double compute_dist(void* ptr_space, double x1[3], double x2[3]){
  auto space = static_cast<ReedsSheppStateSpace*>(ptr_space);
  return space->distance(x1, x2);
}

// deplicated
void sample_points(void* ptr_space, double x1[3], double x2[3], ReedsSheppPathSamplingCallback f, double* arr){
  auto space = static_cast<ReedsSheppStateSpace*>(ptr_space);
  space->sample(x1, x2, 0.1, f, arr);
}

void* rspath_create(void* ptr_space, double q0[3], double q1[3]){
  auto space = static_cast<ReedsSheppStateSpace*>(ptr_space);
  ReedsSheppStateSpace::ReedsSheppPath* ptr_path = new ReedsSheppStateSpace::ReedsSheppPath(space->reedsShepp(q0, q1));
  return static_cast<void*>(ptr_path);
}

double rspath_distance(void* ptr_path){
  auto path = static_cast<ReedsSheppStateSpace::ReedsSheppPath*>(ptr_path);
  return path->length();
}

double rspath_interpolate(void* ptr_path, void* ptr_space, double q0[3], double seg, double* q_out)
{
  auto space = static_cast<ReedsSheppStateSpace*>(ptr_space);
  auto path = static_cast<ReedsSheppStateSpace::ReedsSheppPath*>(ptr_path);
  space->interpolate(q0, *path, seg, q_out);
}

void rspath_delete(void* ptr_path){
  auto path = static_cast<ReedsSheppStateSpace::ReedsSheppPath*>(ptr_path);
  free(path);
}

