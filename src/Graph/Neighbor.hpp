//noa.honigstein@gmail.com
#pragma once


namespace graph {
    struct Neighbor {
        int dest;
        int weight;
        Neighbor* next;
    };
}

