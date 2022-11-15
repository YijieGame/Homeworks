# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import sys

class user(object):
    def __init__(self,name,age):
        self.name = name
        self.age = age

database ={['usr1','pin1']:['name1','10'],['usr2','pin2']:['name2','20'],['usr3','pin3']:['name3','30']}
usrname = input('enter username:')
pin = input('enter pin:')
for i in range(3):
    if [usrname, pin] in database:
        print('log in successfully')
        print('enter:\n1 to correct pin\n2 to add user\n3 to correct info\n4 to inquire info')
        a = input()
        if a=='1':
            old_pin = input('enter old pin:')
            if [usrname,old_pin] in database:
                new_pin = input('enter new pin:')
                temp_info = database[[usrname,old_pin]]
                database.pop([usrname,old_pin])
                database[temp_info] = [usrname,new_pin]
            else:
                sys.exit()
        elif a == '2':
            new_usr = input('enter new usrname:')
            new_pin = input('enter new pin')
            new_name = input('enter name:')
            new_age = input('enter age:')
            database[[new_name,new_age]] = [new_usr,new_pin]
        elif a == '3':
            new_name = input('enter name:')
            new_age = input('enter age:')
            database[[new_name, new_age]] = [usrname, pin]
        elif a=='4':
            temp_pin = input('enter pin:')
            if [usrname,temp_pin] in database:
                database.pop([usrname,temp_pin])
        break
    else:
        sys.exit()