#include<stdio.h>
#include<stdlib.h>
#define N 5;
int main() {
	char stuid[10], name[20];
	float score;
	FILE* outfile;
	int i;
	outfile = fopen_s("scores.txt", "w");
	if (outfile == NULL) {
		printf("���ܴ����ļ���");
		exit(0);
	}
	fprintf(outfile, "ѧ��\t����\t��ѧ�ɼ�\n");
		for (i = 0, i < N; i++) {
			printf("������ѧ��ѧ�š���������ѧ�ɼ���");
			scanf_s("%sd%s%f", stuid, name, &score);
			fprintf(outfile, "%s\t%s\t%f\n", stuid, name, score);
		}
		fclose(outfile);
		return 0;
}