from sys import argv, exit
from helpers import rotate_character

def encrypt(text, rot):
    encrypted_msg = ''
    for x in range(len(message)):
        encrypted_msg += rotate_character(message[x],argv[1])

def user_input_is_valid(cl_argv):
    if argv[1].isdigit() is False:
        exit()

def main():
    message = input("Type a message: ")
    rotation = argv[1]
    encrypt(message, rotation)

if __name__ == '__main__':
    main()