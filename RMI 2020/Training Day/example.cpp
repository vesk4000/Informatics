#include "secret_point.h"

void find_secret_point() {
  double distance_from_1_0 = get_distance(1, 0);
  double distance_from_0_1 = get_distance(0, 1);
  double distance_from_2_2 = get_distance(2, 2);
  the_secret_point_is(1, 1);
}
