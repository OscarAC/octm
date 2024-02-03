// <util/test/test_holder.hpp>
// Copyright(c) 2015-present, Oscar A. Carrera.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#include <utility>
import octm;

void test_construction()
{
    int fa = 10;
    fundamental_holder<int, -1> i {fa};

    test_assert(i.get() == 10);
    test_assert(fa == -1);
}

void test_construction2()
{
  int fa = 10;
  fundamental_holder<int, -1> i;
  i = fa;
  
}

void test_move()
{
    int fa = 7;
    fundamental_holder<int, -1> i {fa};  
    fundamental_holder<int, -1> ii {std::move(i)};
    test_assert(i.get() == -1);
    test_assert(ii.get() == 7);
}


void test_comparison()
{
    int fa = 7;
    int fb = 7;

    fundamental_holder<int, -1> ia {fa};
    fundamental_holder<int, -1> ib {fb};
    test_assert(ia == ib);
    
    fundamental_holder<int, -1> ic {std::move(ia)};
    test_assert(ia < ic);
    test_assert(ic > ia);
}

int main(int, char **)
{

    test_construction();
    test_construction2();
    test_move();
    test_comparison();

    return 0;
}
