assignment=$1
if [ -z "$1" ]; then
	echo "No Assignment number given"
	exit 0
fi
if [ -d submit_dir ]; then
	rm -r submit_dir
fi
mkdir submit_dir

echo "converting any tabs to spaces..."
shopt -s nullglob
for f in *.cpp
do
	expand -t 4 $f > submit_dir/$(basename $f)
done
for f in *.h
do
	expand -t 4 "$f" > "submit_dir/$(basename $f)"
done
for f in *.hpp
do
	expand -t 4 $f > "submit_dir/$(basename $f)"
done

if [ -f Makefile ]; then
	cp Makefile submit_dir/Makefile
fi

cd submit_dir
ssh mst "mkdir -p ~/cs328/hw$assignment"
scp -r * mst:~/cs328/hw$assignment
cd ..
rm -rf "submit_dir"


#todo:
#DONE-setup key based authentication for school ssh or find a way to pass password to the commands
#-move this file into scripts and change the symlink in /usr/bin accordingly
