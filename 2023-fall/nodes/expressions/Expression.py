from __future__ import annotations
from abc import ABC, abstractmethod
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from visitors.Visitor import Visitor



class Expression:
    
    @abstractmethod
    def accept(self, visitor: Visitor):
        pass
