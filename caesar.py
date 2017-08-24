from sys import argv, exit
from helpers import rotate_character

def encrypt(text, rot):
    encrypted_msg = ''
    for x in range(len(text)):
        encrypted_msg += rotate_character(text[x],rot)

    return encrypted_msg

def user_input_is_valid(cl_argv):
    if len(cl_argv) != 2:
        return False
    cl_args = str(cl_argv[1])
    return cl_args.isdigit()

def main():
    user_input_is_valid('a')
    user_input_is_valid(5)

    message = input("Type a message: ")
    rotation = argv[1]
    encrypt(message, rotation)

if __name__ == '__main__':
    main()