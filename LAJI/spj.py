import sys

inputFileName = sys.argv[1]
standardFileName = sys.argv[2]
outputFileName = sys.argv[3]
logFileName = sys.argv[4]
codeFileName = "main.c"

sout = open(outputFileName, "r").read()
sstd = open(standardFileName, "r").read()
scode = open(codeFileName, "r").read()
if sout.count == 0:
    print("0\nNo Output")
    sys.exit(1)
if sstd.count == 0:
    print("0\nSPJ Error")
    sys.exit(1)
if scode.count == 0:
    print("0\nSPJ Error")
    sys.exit(1)
if "time.h" in scode:
    print("0\n\"time.h\" is not permitted")
    sys.exit(1)
sstd = sstd.replace("\r", "").strip("\r\n ")
sout = sout.replace("\r", "").strip("\r\n ")
if sstd == sout:
    print("1\nAccepted")
    sys.exit(0)
sstd = sstd.replace("\n", "").replace(" ", "").strip("\r\n ")
sout = sout.replace("\n", "").replace(" ", "").strip("\r\n ")
if sstd == sout:
    print("0\nPresentation Error")
    sys.exit(0)
print("0\nWrong Answer")