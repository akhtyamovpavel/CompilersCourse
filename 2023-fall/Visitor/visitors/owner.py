from elements.home import Home
from elements.room import Room
from visitors.visitor import Visitor


class Owner(Visitor):
    def visit_home(self, element: Home):
        print('I am in home')
        for room in element.rooms:
            print('Going to room')
            room.accept(self)

    def visit_room(self, element: Room):
        print('I am at room')