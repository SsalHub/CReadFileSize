#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	
	fp = fopen("src.txt", "r");
	
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *buffer = (char *)malloc(fileSize + 1);

    fread(buffer, 1, fileSize, fp);
    fclose(fp);
    
    fp = fopen("dst.txt", "w");
	fwrite(buffer, 1, sizeof(buffer), fp);
	char dstExtraText[64] = " has read with fseek() and ftell().\n";
	fwrite(dstExtraText, sizeof(char), sizeof(dstExtraText), fp);
	
	printf("File I/O stream successfully done.\nResult : %s%s", buffer, dstExtraText);
	
	return 0;
}