﻿//amd 3.45GHZ cost time 3600ms
main
{
	start=rf.tick
	for i=1 to 10
		rf.cmd("rpp example\\1.h")
	putsl
	putsl(rf.tick-start)
}