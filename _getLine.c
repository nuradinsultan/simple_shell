#include "shell.h"

#define BUF_SIZE 256

/**
 * _getLine - recodage getLine
 * @file: file
 *
 * Return: line read
 */

char *_getLine(const int file)
{
	static char readding[BUF_SIZE];
	static int index = BUF_SIZE;
	int getting = 0;
	int count = 0;
	char *get = NULL;

	if (getting == 0 && index >= (BUF_SIZE - 1))
	{
		index = 0;
		getting = read(file, readding, BUF_SIZE + 1);
		readding[getting] = '\0';
	}

	if (index <= BUF_SIZE && readding[index] != '\0')
	{
		get = malloc((sizeof(*get) * BUF_SIZE));
		while (readding[index] != '\n' && readding[index] != '\0')
			get[count++] = readding[index++];
		get[count] = '\0';
		if (readding[index] != '\0')
			index = index + 1;
	}
	return (get);
}
