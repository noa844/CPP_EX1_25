//noa.honigstein@gmail.com
#pragma once

#include "Neighbor.hpp"

namespace graph {
    struct Node {
        int number;
        Neighbor* adjList;
    };
}

