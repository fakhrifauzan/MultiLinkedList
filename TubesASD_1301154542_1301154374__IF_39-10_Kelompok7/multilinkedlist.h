#ifndef MULTILINKEDLIST_H_INCLUDED
#define MULTILINKEDLIST_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

#define Nil NULL
#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define anak(P) (P)->anak
#define rumah(P) (P)->rumah

struct cabang{
  int id;
  string nama;
  string kota;
  string provinsi;
};

struct ftr{
  string nama;
  string fitur;
  int lt;
  int lb;
  int kt;
  int km;
  int kp;
  int kr;
  int lantai;
  int listrik;
};

struct cluster{
  string nama;
  ftr fitur;
  int harga;
  int rmh;
  int booking;
};

struct admin{
  string nama;
  int id;
  string pw;
};

struct rumah{
  int idP;
  string nama;
  string noktp;
};

typedef cabang infotypeCabang;
typedef cluster infotypeCluster;
typedef rumah infotypeRumah;
typedef struct ElmListCabang *addressCabang;
typedef struct ElmListCluster *addressCluster;
typedef struct ElmListRumah *addressRumah;

struct ElmListCabang{
  addressCabang prev;
  infotypeCabang info;
  addressCluster anak;
  addressCabang next;
};

struct ElmListCluster{
  addressCluster prev;
  infotypeCluster info;
  addressRumah rumah;
  addressCluster next;
};

struct ElmListRumah{
  infotypeRumah info;
  addressRumah next;
  addressRumah prev;
};

struct ListInduk{
  addressCabang first;
  addressCabang last;
};

void createList(ListInduk &L);
addressCabang alokasiInduk(infotypeCabang x);
addressCluster alokasiAnak(infotypeCluster x);
addressRumah alokasiRumah(infotypeRumah x);
void dealokasiInduk(addressCabang &P);
void dealokasiAnak(addressCluster &P);
void dealokasiRumah(addressRumah &P);
void insertFirstInduk(ListInduk &L, addressCabang P);
void insertFirstAnak(ListInduk &L, addressCabang Pi,addressCluster Pa);
void insertAfterInduk(ListInduk &L, addressCabang Prec, addressCabang P);
void insertLastInduk(ListInduk &L, addressCabang P);
void insertLastAnak(ListInduk &L, addressCabang Pi, addressCluster Pa);
void insertLastRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah Pr);
addressCabang findElmInduk(ListInduk L, infotypeCabang x);
addressCluster findElmAnak(ListInduk L, addressCabang Pi ,infotypeCluster x);
addressRumah findElmRumah(ListInduk L, addressCabang Pi, addressCluster Pa, infotypeRumah x);
void deleteFirstInduk(ListInduk &L, addressCabang &P);
void deleteFirstAnak(ListInduk &L, addressCabang Pi, addressCluster &Pa);
void deleteFirstRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah &Pr);
void deleteLastInduk(ListInduk &L, addressCabang &P);
void deleteLastAnak(ListInduk &L, addressCabang Pi, addressCluster &Pa);
void deleteLastRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah &Pr);
void deleteAfterInduk(ListInduk &L, addressCabang Prec, addressCabang &P);
void deleteAfterAnak(ListInduk &L, addressCluster Prec, addressCluster &Pa);
void deleteAfterRumah(ListInduk &L, addressRumah Prec, addressRumah &Pr);
void printInfo(ListInduk L);
void printInfoCluster(ListInduk L, addressCabang P);
void printInfoListCabang(ListInduk L);
void printInfoListBooking(ListInduk L, addressCabang Pi, addressCluster Pa);
void menu();
void data(ListInduk &L);
bool isClusterEmpty(addressCabang Pi);
bool isListEmpty(ListInduk L);
void deleteData(ListInduk &L, addressCabang &P);
void deleteDataAnak(ListInduk &L, addressCabang Pi, addressCluster &Pa);
void deleteDataRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah &Pr);
//ProcedureMenu
void menuInputCabang(ListInduk &L, int &cC);
void menuInputCluster(ListInduk L);
void menuInputBooking(ListInduk L, int &cP);
void menuEditCabang(ListInduk &L);
void menuEditCluster(ListInduk L);
void menuEditBooking(ListInduk L);
void menuViewCluster(ListInduk L);
void menuViewBooking(ListInduk L);
void menuDeleteCabang(ListInduk &L);
void menuDeleteCluster(ListInduk L);
void menuDeleteBooking(ListInduk L);

#endif // MULTILINKEDLIST_H_INCLUDED
