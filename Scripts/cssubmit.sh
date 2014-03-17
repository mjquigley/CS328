assignment=$1
cscopy $1
ssh mst "cd ~/cs328/hw$assignment;cssubmit 328 a $assignment"
