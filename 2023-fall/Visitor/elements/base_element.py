from abc import ABC, abstractmethod

class Visitor:
    pass

class BaseElement(ABC):

    @abstractmethod
    def accept(self, visitor: Visitor):
        pass
