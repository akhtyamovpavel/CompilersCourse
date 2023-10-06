from elements.home import Home
from elements.room import Room
from visitors.guest import Guest
from visitors.owner import Owner


if __name__ == '__main__':
    home = Home()
    home.rooms = [Room(), Room()]

    owner = Owner()
    home.accept(owner)

    print('Guest')

    guest = Guest()
    home.accept(guest)
