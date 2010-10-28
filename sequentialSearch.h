#include <vector>
using namespace std;

template <class Comparable>
size_t SequentialSearch(const vector<Comparable> &v, Comparable x)
{
    for (size_t i = 0; i < v.size(); i++)
        if (v[i] == x)
           return i;   // encontrou
    return -1;     // não encontrou
}
