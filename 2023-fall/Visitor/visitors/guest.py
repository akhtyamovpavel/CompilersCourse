from elements.home import Home
from elements.room import Room
from visitors.visitor import Visitor


class Guest(Visitor):
    def visit_home(self, element: Home):
        print('I am at home')

    def visit_room(self, element: Room):
        pass