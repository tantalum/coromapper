CFLAGS = `pkg-config --cflags playerc`
CLIBS = `pkg-config --libs playerc`

grippy_controller: grippy_controller.c
	gcc -o grippy_controller $(CFLAGS) grippy_controller.c $(CLIBS)
list_devices: list_devices.c
	gcc -o list_devices $(CFLAGS) list_devices.c $(CLIBS)

clean:
	rm -f *.o grippy_controller list_devices

all: grippy_controller	list_devices
