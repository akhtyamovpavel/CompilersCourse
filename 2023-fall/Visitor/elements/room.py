from elements.base_element import BaseElement, Visitor


class Room(BaseElement):
    def accept(self, visitor: Visitor):
        print('Hello from Room')
        return visitor.visit_room(self)
