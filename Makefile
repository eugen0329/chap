TARGET = chata

all: $(TARGET)

$(TARGET): main.c receiver.c sender.c util.c sender.h util.h util.h
	gcc main.c receiver.c sender.c util.c -o $(TARGET) -lncurses -lform -lpthread

clean:
	rm $(TARGET)
