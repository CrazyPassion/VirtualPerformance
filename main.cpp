#include <iostream>
#include <random>
#include <time.h>
#include "VirtualPerformance.hpp"

using namespace VirtualPerformance;

#define ARRAY_SIZE 1024
#define TEST_ITERATIONS 10000

float RandomFloat(float s, float e)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(s, e);
    return dis(gen);
}

template <class T>
void InitWithRandom( T *ptr, int num )
{
    while( num > 0 )
    {
        ptr->SetX( RandomFloat(-1024.f, 1024.0f) );
        ptr->SetY( RandomFloat(-1024.f, 1024.0f) );
        ptr->SetZ( RandomFloat(-1024.f, 1024.0f) );
        ptr->SetW( RandomFloat(-1024.f, 1024.0f) );
        ++ptr;
        --num;
    }
}

#define restrict

template <class T>
void SumTest( T * restrict in1, T * restrict in2, T * restrict out, const int num )
{
    for ( int i = 0; i < num ; ++i )
    {
        out[i].SetX( in1[i].GetX() + in2[i].GetX() );
        out[i].SetY( in1[i].GetY() + in2[i].GetY() );
        out[i].SetZ( in1[i].GetZ() + in2[i].GetZ() );
        out[i].SetW( in1[i].GetW() + in2[i].GetW() );
    }
}

template <class T>
float TestTimings( )
{
    // set up input and output and preheat the cache
    T A[ ARRAY_SIZE ];
    T B[ ARRAY_SIZE ];
    T C[ ARRAY_SIZE ];

    InitWithRandom( A , ARRAY_SIZE );//1024*4 set
    InitWithRandom( B , ARRAY_SIZE );
    InitWithRandom( C , ARRAY_SIZE );

    clock_t t;
    unsigned long long retval = 0;
    int dontOptimizeThisLoopToNothing = 0;
    for ( int i = 0 ; i < TEST_ITERATIONS ; ++i )
    {
        t = clock();
        SumTest( A, B, C, ARRAY_SIZE );
        t = clock() - t;
        dontOptimizeThisLoopToNothing = i;
        retval += t;
    }
    // force compiler to actually use the data so it doesn't vanish the loop above
    float ac = 0;
    for ( int i = 0 ; i < ARRAY_SIZE ; ++i )
    {
        ac += C[i].GetX();
        ac += C[i].GetY();
        ac += C[i].GetZ();
        ac += C[i].GetW();
    }
    printf( "%f %d\n", ac, dontOptimizeThisLoopToNothing  ); // just ignore these
    return (((float)retval)/CLOCKS_PER_SEC);
}

void RunTest()
{
    // get timings for each type
    float tVirt, tDirect, tInline;
    tVirt = TestTimings< TestVector4_Virtual >();
    tDirect = TestTimings< TestVector4_Direct >();
    tInline = TestTimings< TestVector4_Inline >();

    printf( "\n%d iterations over %d vectors\n", TEST_ITERATIONS , ARRAY_SIZE );
    printf( "virtual: %.3f s\n", tVirt );
    printf( "direct: %.3f s\n", tDirect );
    printf( "inline: %.3f s\n", tInline );
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    RunTest();
    return 0;
}