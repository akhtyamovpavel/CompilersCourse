from abc import ABC, abstractmethod

from elements.home import Home
from elements.room import Room


class Visitor(ABC):

    @abstractmethod
    def visit_home(self, element: Home):
        pass

    @abstractmethod
    def visit_room(self, element: Room):
        pass

    # visit(Room* room)
    # visit(Home* home)
