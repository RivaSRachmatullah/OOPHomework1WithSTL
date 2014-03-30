# - Berikut adalah contoh Makefile untuk autograde
# - Harus ada perintah compile-test untuk kompilasi dan grade untuk eksekusi
# - OUTPUT adalah variabel yang diperlukan, tidak perlu diubah.
# - ADT dan MAIN adalah variabel yang berisi nama-nama file,
#   silahkan diubah sesuai kebutuhan.

OUTPUT=bin
ADT1=Time/Time
ADT2=Date/Date
ADT3=DateTime/DateTime
ADT4=Teller/Teller
ADT5=Event/Event
MAIN=main

compile-test: $(MAIN).cpp $(ADT5).o $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o
	g++ -o -std=c++0x $(MAIN) $(MAIN).cpp $(ADT5).o $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o

grade:
	./$(MAIN)
