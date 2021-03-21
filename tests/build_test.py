import sys, codecs, os
from os import listdir
from os.path import isfile, join, isdir
from shutil import copyfile

PNAME = 'DIGITS'
INDIR = './'
OUTDIR = INDIR + 'testset'
NO_TEST = 0

def normalize(filename):
	non = 0
	rem = -1
	for i in range(len(filename)):
		if filename[i] in '0123456789':
			non += 1
			if rem == -1:
				rem = i

	if non < 2:
		return filename[:rem] + '0'*(2-non) + filename[rem:]
	else:
		return filename


def make_input(filepath, filename):
	global NO_TEST
	dest = OUTDIR + '/' + normalize(filename) + '.txt'
	copyfile(filepath, dest)
	NO_TEST += 1


def crawl(INDIR, fn=None):
	for filename in listdir(INDIR):
		filepath = join(INDIR,filename)
		if filename[0] == '.': 
			continue;
		# print(filename)
		if isfile(filepath):
			if '.inp' in filename.lower():
				make_input(filepath, fn)
			print(filename)
		else:
			if isdir(filepath): 
				crawl(filepath,filename)


if __name__ == '__main__':
	try:
		os.mkdir(OUTDIR)
	except OSError:
		print ("Creation of the directory %s failed" % OUTDIR)
	else:
		print ("Successfully created the directory %s " % OUTDIR)
	crawl(INDIR)