#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define __USE_XOPEN_EXTENDED 1
#include <ftw.h>

unsigned long long totalSize = 0;

int sum( const char *fpath, const struct stat *sb, int typeflag ) {

    totalSize += sb->st_size;

    return 0;

}

int main( int argc, char **args ) {

    clock_t t = clock( );

    if( ftw( args[ 1 ], &sum, 1 ) ) {

        return 2;

    }

    printf( "Path evaluated: %s\nTotal size: %dMB\nTime elapsed: %.2fms\n", args[ 1 ], totalSize / ( 1024 * 1024 ), ( ( ( double )( clock( ) - t ) / CLOCKS_PER_SEC ) * 1000 ) );

    return 0;

}