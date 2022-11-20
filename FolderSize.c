#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define __USE_XOPEN_EXTENDED 1
#include <ftw.h>

unsigned long long totalSize = 0;

int sum( const char *fpath, const struct stat *sb, int typeflag ) {

	totalSize += sb->st_size;

	return 0;

}

int main( int argc, char **args ) {

	if( argc < 2 ) {

		printf( "Usage: %s [Path]\n", args[ 0 ] );

		return 0;

	}

	if( access( args[ 0 ], R_OK ) != 0 ) {

		printf( "Folder could not be accessed\n" );

		return 0;

	}

	clock_t t = clock( );

	if( ftw( args[ 1 ], &sum, 1 ) ) {

		return 2;

	}

	printf( "Path evaluated: %s\nTotal size: %dMB\nTime elapsed: %.2fms\n", args[ 1 ], totalSize / ( 1024 * 1024 ), ( ( ( double )( clock( ) - t ) / CLOCKS_PER_SEC ) * 1000 ) );

	return 0;

}
