SYSTEM CALL:pipes()

PROTOTYPE: int pipe(int fd[2]);
RETURNS: 0 on the success
	-1 on error: errno = 	EMFILE (no free descriptors)
				EMFILE (system file table is full)
				EFAULT (fd array is not valid)
NOTES: fd[0] is set up for reading, fe[1] is set up for writing Pipe() is FIFO.
