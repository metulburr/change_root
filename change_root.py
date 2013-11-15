
import subprocess
import sys

def execute(string):
	proc = subprocess.Popen(string.split())
	proc.wait()
	print(string)

NUMBER = input('input integer for /dev/sda: ')
try:
	int(NUMBER)
except:
	print('You must enter an integer for sda')
	sys.exit()

one = 'sudo mount /dev/sda{} /mnt'.format(NUMBER)
two = 'sudo mount -t proc none /mnt/proc'
three = 'sudo mount -o bind /dev /mnt/dev'
four = 'sudo mount -o bind /sys /mnt/sys'
five = 'sudo chroot /mnt'

uone = 'sudo umount /mnt/sys'
utwo = 'sudo umount /mnt/dev'
uthree = 'sudo umount /mnt/proc'
ufour = 'sudo umount /mnt'

print('changing to root of /dev/sda{}'.format(NUMBER))
print('"exit" to unmount')
execute(one)
execute(two)
execute(three)
execute(four)
execute(five)

#after user enters 'exit' will return to python to unmount

print('unmounting...')
execute(uone)
execute(utwo)
execute(uthree)
execute(ufour)

