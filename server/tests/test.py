##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## test
##

import subprocess
import socket
import unittest
import time

DEBUG = False

class Server():
    def __init__(self, port=4000):
        self.port = port
        self.process = subprocess.Popen([f"./myteams_server {port}"], shell=True)
        time.sleep(0.1)        
        self.soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.soc.connect(("127.0.0.1", self.port))
        r = self.soc.recv(1000).decode()
    
    def send(self, command):
        self.soc.send((f"{command}\r\n").encode())

class MyTeamsTest(unittest.TestCase):
    port = 4001

    @classmethod
    def setUp(self):
        self.server = Server(MyTeamsTest.port)
        MyTeamsTest.port = MyTeamsTest.port + 1
    
    @classmethod
    def tearDown(self):
        self.server.soc.close()
        self.server.process.kill()

    def send_assert_code(self, command, excepted_code):
        self.server.send(command)
        r = self.server.soc.recv(1000).decode()
        if DEBUG:
            print(f"r={r}")
        s = r.split(' ', 1)
        self.assertEqual(s[-1][-2:], "\r\n")
        self.assertEqual(int(s[0]), excepted_code)



class TestLogin(MyTeamsTest):
    def test(self):
        self.send_assert_code("login toto zea", 500)
        self.send_assert_code("login toto", 200)
        self.send_assert_code("login tata", 300)
        self.send_assert_code("logout aze", 500)
        self.send_assert_code("logout", 200)
        self.send_assert_code("logout", 300)
        

if __name__ == "__main__":
    unittest.main()