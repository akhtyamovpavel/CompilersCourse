from elements.base_element import BaseElement, Visitor
from elements.room import Room


class Home(BaseElement):
    
    rooms: list[Room] = []

    def accept(self, visitor: Visitor):
        return visitor.visit_home(self)
