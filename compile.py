import subprocess

output = 'dcl.exe'

packages = [
	'main.c',
	'token.c',
	'dcl.c',
	'buf.c'
]

cmd = f'gcc {" ".join(packages)} -o bin/{output}'

subprocess.run(cmd)