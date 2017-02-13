#include "multilinkedlist.h"

void menu(){
    ListInduk L;
    // cabang cbg;
    // cluster cls;
    // rumah r;
    // string ktp;

    createList(L);

    // data(L);
    int cC = 1;
    int cP = 1;

    int pil;
    do{
        system("CLS");
        cout << "===============================" << endl;
        cout << "Aplikasi Pemesanan Rumah PT.Ezy" << endl;
        cout << "===============================" << endl;
        cout << " -- INPUT -- " << endl;
        cout << "1. Input Cabang" << endl;
        cout << "2. Input Cluster" << endl;
        cout << "3. Input Booking Rumah" << endl;
        cout << " -- EDIT -- " << endl;
        cout << "4. Edit Cabang" << endl;
        cout << "5. Edit Cluster" << endl;
        cout << "6. Edit Booking Rumah" << endl;
        cout << " -- VIEW -- " << endl;
        cout << "7. View Cabang" << endl;
        cout << "8. View Cluster" << endl;
        cout << "9. View Booking Rumah" << endl;
        cout << " -- DELETE -- " << endl;
        cout << "10. Delete Cabang" << endl;
        cout << "11. Delete Cluster" << endl;
        cout << "12. Delete Booking Rumah" << endl;
        cout << "13. Exit" << endl;
        cout << "Masukan Pilihan : ";
        cin >> pil;
        switch(pil){
            case 1 : {
              system("cls");
              menuInputCabang(L,cC);
              break;
            }
            case 2 : {
              system("cls");
              menuInputCluster(L);
              break;
            }
            case 3 : {
              system("cls");
              menuInputBooking(L,cP);
              break;
            }
            case 4 : {
              system("cls");
              menuEditCabang(L);
              break;
            }
            case 5 : {
              system("cls");
              menuEditCluster(L);
              break;
            }
            case 6 : {
              system("cls");
              menuEditBooking(L);
              break;
            }
            case 7 : {
              system("cls");
              printInfo(L);
              break;
            }
            case 8 : {
              system("cls");
              menuViewCluster(L);
              break;
            }
            case 9 : {
              system("cls");
              menuViewBooking(L);
              break;
            }
            case 10 : {
              system("cls");
              menuDeleteCabang(L);
              break;
            }
            case 11 : {
              system("cls");
              menuDeleteCluster(L);
              break;
            }
            case 12 : {
              system("cls");
              menuDeleteBooking(L);
              break;
            }
        }
        getch();
    } while (pil != 13);
}


void menuInputCabang(ListInduk &L, int &cC) {
  cabang cbg;
  addressCabang Pi;

  system("CLS");
  cout << ".:: Input Cabang ::." << endl;
  cout << "Nama Cabang Baru : ";
  cin >> cbg.nama;
  cout << "Kota : ";
  cin >> cbg.kota;
  cout << "Provinsi : ";
  cin >> cbg.provinsi;
  cbg.id = cC;
  Pi = alokasiInduk(cbg);
  insertLastInduk(L,Pi);
  cout << "Cabang " << cbg.nama << " dengan ID : " << cC << endl;
  cC++;
  cout << "Cabang " << cbg.nama << " Berhasil Di Inputkan!" << endl;
}

void menuInputCluster(ListInduk L) {
  cluster cls;
  cabang cbg;
  addressCabang Pi;
  addressCluster Pa;

  system("CLS");
  Pi = NULL;
  if (isListEmpty(L)) {
    cout << "Perusahaan ini belum memiliki cabang!" << endl;
    cout << "Silakan input terlebih dahulu.." << endl;
    return;
  }
  do {
    printInfoListCabang(L);
    cout << ".:: Input Cluster ::." << endl;
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL){
      cout << "Cabang Tidak Ada! Silakan input kembali!";
      system("CLS");
    }
    //cout << "nilai Pi : " << Pi << endl;
  } while(Pi == NULL);
  system("CLS");
  cout << "Nama Cabang : " << info(Pi).nama << endl;
  do {
    cout << "Nama Cluster Baru : ";
    cin >> cls.nama;
  } while(cls.nama.length() < 3);
  // getline(cin,cls.nama);
  cout << "Harga : ";
  cin >> cls.harga;
  cout << "Jumlah Rumah : ";
  cin >> cls.rmh;
  cout << ".:: Fitur ::." << endl;
  cout << "Luas Tanah : ";
  cin >> cls.fitur.lt;
  cout << "Luas Bangunan : ";
  cin >> cls.fitur.lb;
  cout << "Kamar Tidur : ";
  cin >> cls.fitur.kt;
  cout << "Kamar Pembantu : ";
  cin >> cls.fitur.kp;
  cout << "Kamar Mandi : ";
  cin >> cls.fitur.km;
  cout << "Kolam Renang : ";
  cin >> cls.fitur.kr;
  cout << "Lantai : ";
  cin >> cls.fitur.lantai;
  cout << "Listrik (kWh): ";
  cin >> cls.fitur.listrik;
  cls.booking = 0;
  Pa = alokasiAnak(cls);
  insertLastAnak(L,Pi,Pa);
  cout << "Data Berhasil Di Inputkan!" << endl;
}

void menuInputBooking(ListInduk L, int &cP) {
  cabang cbg;
  cluster cls;
  rumah rmh;
  addressCabang Pi;
  addressCluster Pa;
  addressRumah Pr;

  system("CLS");
  Pi = NULL;
  if (isListEmpty(L)) {
    cout << "Perusahaan ini belum memiliki cabang!" << endl;
    cout << "Silakan input terlebih dahulu.." << endl;
    return;
  }
  do {
    printInfoListCabang(L);
    cout << ".:: Cari Cabang ::." << endl;
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL){
      cout << "Cabang Tidak Ada! Silakan input kembali!";
      system("CLS");
    }
    //cout << "nilai Pi : " << Pi << endl;
  } while(Pi == NULL);
  if (isClusterEmpty(Pi)) {
    cout << "Cabang " << info(Pi).nama << " belum memiliki cluster!" << endl;
    cout << "Silakan input terlebih dahulu.." << endl;
    return;
  }
  system("CLS");
  do {
    cout << "Nama Cabang : " << info(Pi).nama << endl;
    printInfoCluster(L,Pi);
    cout << ".:: Cari Cluster ::." << endl;
    cout << "Masukan Nama Cluster : ";
    cin >> cls.nama;
    Pa = findElmAnak(L,Pi,cls);
    if (Pa == NULL){
      cout << "Cluster Tidak Ada! Silakan input kembali!";
    }
  } while(Pa == NULL);
  system("CLS");
  cout << "Nama Cabang : " << info(Pi).nama << endl;
  cout << "Nama Cluster : " << info(Pa).nama << endl;
  cout << "Jumlah Booking " << info(Pa).booking << " of " << info(Pa).rmh << endl;
  printInfoListBooking(L,Pi,Pa);
  cout << "== PROSES BOOKING == " << endl;
  if (info(Pa).booking == info(Pa).rmh) {
    cout << "Seluruh Rumah pada Cluster " << info(Pa).nama << " Sudah diBooking!" << endl;
    cout << "Silakan cari cluster lainnya :)" << endl;
    return;
  } else {
    cout << "Masukan Nama : ";
    cin >> rmh.nama;
    cout << "Masukan No KTP : ";
    cin >> rmh.noktp;
    rmh.idP = cP;
    Pr = alokasiRumah(rmh);
    insertLastRumah(L,Pi,Pa,Pr);
    cP++;
    info(Pa).booking++;
    cout << "Rumah Berhasil di Booking (y)" << endl;
  }
}

void menuEditCabang(ListInduk &L) {
  cabang cbg;
  addressCabang Pi;

  if (isListEmpty(L)) {
    cout << "Cabang belum ada, silakan input!" << endl;
    return;
  } else {
    printInfoListCabang(L);
    cout << ".:: EDIT CABANG ::." << endl;
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL){
      cout << "Cabang Tidak Ada! Silakan input duluu :)";
      return;
    } else {
      system("cls");
      cout << "Nama Cabang : " << info(Pi).nama << endl;
      cout << "===== EDIT ======" << endl;
      cout << "Nama(baru) : ";
      cin >> cbg.nama;
      info(Pi).nama = cbg.nama;
      cout << "Nama Berhasil Diganti!" << endl;
      cout << "Nama (baru) : " << info(Pi).nama << endl;
    }
  }
}

void menuEditCluster(ListInduk L) {
  cabang cbg;
  cluster cls;
  addressCabang Pi;
  addressCluster Pa;

  system("CLS");
  if (isListEmpty(L)) {
    cout << "Cabang belum ada, silakan input!" << endl;
    return;
  } else {
    printInfoListCabang(L);
    cout << ".:: EDIT CLUSTER ::." << endl;
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL) {
      cout << "Cabang dengan id:"<< cbg.id << " tidak ada, silakan input!" << endl;
      return;
    } else {
      system("CLS");
      cout << "Nama Cabang : " << info(Pi).nama << endl;
      if (isClusterEmpty(Pi)) {
        cout << "Cluster Tidak Ada! Silakan input kembali!";
        return;
      } else {
        printInfoCluster(L,Pi);
        cout << "Masukan Nama Cluster : ";
        cin >> cls.nama;
        Pa = findElmAnak(L,Pi,cls);
        if (Pa == NULL){
          cout << "Cluster Tidak Ada! Silakan input kembali!";
          return;
          //system("CLS");
        }
        //cout << "nilai Pi : " << Pi << endl;
        cout << "Nama Cabang : " << info(Pi).nama << endl;
        cout << "Nama Cluster : " << info(Pa).nama << endl;
        cout << "Harga Cluster " << info(Pa).nama << " : " << info(Pa).harga << endl;
        cout << "===== EDIT ======" << endl;
        cout << "Harga(baru) : ";
        cin >> cls.harga;
        info(Pa).harga = cls.harga;
        cout << "Harga Cluster " << info(Pa).nama  << " Berhasil Diganti!" << endl;
        cout << "Harga (baru) : " << info(Pa).harga << endl;
      }
    }
  }
}

void menuEditBooking(ListInduk L) {
  cabang cbg;
  cluster cls;
  rumah rmh;
  addressCabang Pi;
  addressCluster Pa;
  addressRumah Pr;

  if (isListEmpty(L)) {
    cout << "Cabang belum ada, silakan input!" << endl;
    return;
  } else {
    system("CLS");
    printInfoListCabang(L);
    cout << ".:: EDIT BOOKING RUMAH ::." << endl;
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL) {
      cout << "Cabang Tidak Ada! Silakan input kembali!";
      return;
    } else {
      system("CLS");
      if (isClusterEmpty(Pi)) {
        cout << "Cluster Tidak Ada! Silakan input kembali!";
        return;
      } else {
        cout << "Nama Cabang : " << info(Pi).nama << endl;
        printInfoCluster(L,Pi);
        cout << "Masukan Nama Cluster : ";
        cin >> cls.nama;
        Pa = findElmAnak(L,Pi,cls);
        if (Pa == NULL){
          cout << "Cluster Tidak Ada! Silakan input kembali!";
          return;
        }
        cout << "Nama Cabang : " << info(Pi).nama << endl;
        cout << "Nama Cluster : " << info(Pa).nama << endl;
        if (info(Pa).booking == 0) {
          cout << "Belum ada rumah yg dibooking pada cluster ini:)" << endl;
          return;
        } else {
          printInfoListBooking(L,Pi,Pa);
          cout << "== EDIT BOOKING RUMAH == " << endl;
          cout << "Masukan idPemesanan : ";
          cin >> rmh.idP;
          Pr = findElmRumah(L,Pi,Pa,rmh);
          if (Pr == NULL){
            cout << "Nomor Pemesanan Tidak ditemukan!";
            return;
          }
          cout << "idPemesanan Rumah No." << info(Pr).idP << " : "  << info(Pr).nama << " (" << info(Pr).noktp << ") " << endl;
          cout << "Masukan Nama (baru) : ";
          cin >> rmh.nama;
          cout << "Masukan No KTP (baru) : ";
          cin >> rmh.noktp;
          info(Pr).nama = rmh.nama;
          info(Pr).noktp = rmh.noktp;
          cout << "idPemesanan Rumah No." << info(Pr).idP << " pada Cluster "<< info(Pa).nama <<" berhasil diganti!" << endl;
          cout << " -- Setelah Perubahan Data -- " << endl;
          cout << "idPemesanan Rumah No." << info(Pr).idP << " : "  << info(Pr).nama << " (" << info(Pr).noktp << ") " << endl;
        }
      }
    }
  }
}

void menuViewCluster(ListInduk L) {
  cabang cbg;
  cluster cls;
  addressCabang Pi;

  if (isListEmpty(L)) {
    cout << "Cabang Belum ada, silahkan di input!" << endl;
    return;
  } else {
    printInfoListCabang(L);
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL) {
      cout << "Cabang Tidak ada, silakan Input kembali!" << endl;
      return;
    } else {
      system("CLS");
      cout << "Nama Cabang : " << info(Pi).nama << endl;
      printInfoCluster(L,Pi);
    }
  }
}

void menuViewBooking(ListInduk L) {
  cabang cbg;
  cluster cls;
  addressCabang Pi;
  addressCluster Pa;

  if (isListEmpty(L)) {
    cout << "Perusahaan ini belum memiliki cabang!" << endl;
    cout << "Silakan input terlebih dahulu.." << endl;
    return;
  } else {
    do {
      printInfoListCabang(L);
      cout << ".:: Cari Cabang ::." << endl;
      cout << "Masukan ID Cabang : ";
      cin >> cbg.id;
      Pi = findElmInduk(L,cbg);
      if (Pi == NULL){
        cout << "Cabang Tidak Ada! Silakan input kembali!";
        system("CLS");
      }
    } while(Pi == NULL);
    if (isClusterEmpty(Pi)) {
      cout << "Cabang " << info(Pi).nama << " belum memiliki cluster!" << endl;
      cout << "Silakan input terlebih dahulu.." << endl;
      return;
    }
    system("CLS");
    do {
      cout << "Nama Cabang : " << info(Pi).nama << endl;
      printInfoCluster(L,Pi);
      cout << ".:: Cari Cluster ::." << endl;
      cout << "Masukan Nama Cluster : ";
      cin >> cls.nama;
      Pa = findElmAnak(L,Pi,cls);
      if (Pa == NULL){
        cout << "Cluster Tidak Ada! Silakan input kembali!";
      }
    } while(Pa == NULL);
    system("CLS");
    cout << "Nama Cabang : " << info(Pi).nama << endl;
    cout << "Nama Cluster : " << info(Pa).nama << endl;
    printInfoListBooking(L,Pi,Pa);
  }
}

void menuDeleteCabang(ListInduk &L) {
  cabang cbg;
  char key;
  addressCabang Pi;

  system("CLS");
  if (isListEmpty(L)) {
    cout << "Cabang Belum ada, silahkan di input!" << endl;
    return;
  } else {
    system("CLS");
    cout << ".:: Delete Cabang ::." << endl;
    printInfoListCabang(L);
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL) {
      cout << "Cabang Tidak Ada! Silakan input kembali!" << endl;
      return;
    } else {
      cout << "Yakin ingin menghapus Cabang " << info(Pi).nama << " (y/n) : " << endl;
      cin >> key;
      if ((key == 'y') or (key == 'Y')) {
        if (anak(Pi) != NULL) {
          addressCluster z = anak(Pi);
          while (next(z) != NULL) {
            deleteLastAnak(L,Pi,z);
          }
          cout << "Seluruh Cluster Berhasil Diapus" << endl;
        }
        cbg = info(Pi);
        deleteData(L,Pi);
        cout << "Cabang " << cbg.nama << " Berhasil Diapus!";
      } else {
        cout << "Anda Tidak melakukan perubahan!" << endl;
      }
    }
  }
}

void menuDeleteCluster(ListInduk L) {
  cabang cbg;
  cluster cls;
  char key;
  addressCabang Pi;
  addressCluster Pa;

  if (isListEmpty(L)) {
    cout << "Cabang Belum ada, silahkan di input!" << endl;
    return;
  } else {
    system("cls");
    cout << ".:: DELETE CLUSTER ::." << endl;
    printInfoListCabang(L);
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL) {
      cout << "Cabang Tidak Ada! Silakan input kembali!" << endl;
      return;
    } else {
      system("CLS");
      cout << "Nama Cabang : " << info(Pi).nama << endl;
      if (isClusterEmpty(Pi)) {
        cout << "Cabang ini belum memiliki Cluster, silakan input terlebih Dahulu!" << endl;
        return;
      } else {
        printInfoCluster(L,Pi);
        cout << "Masukan Nama Cluster : ";
        cin >> cls.nama;
        Pa = findElmAnak(L,Pi,cls);
        if (Pa == NULL){
          cout << "Cluster Tidak Ada! Silakan input kembali!";
          return;
        }
        cout << "Nama Cabang : " << info(Pi).nama << endl;
        cout << "Yakin ingin menghapus Cluster " << info(Pa).nama << " (y/n) : " << endl;
        cin >> key;
        if ((key == 'y') or (key == 'Y')) {
          cls = info(Pa);
          deleteDataAnak(L,Pi,Pa);
          cout << "Cluster " << cls.nama << " Berhasil Diapus!";
        } else {
          cout << "Anda Tidak melakukan perubahan!" << endl;
        }
      }
    }
  }
}

void menuDeleteBooking(ListInduk L) {
  cabang cbg;
  cluster cls;
  rumah rmh;
  char key;
  addressCabang Pi;
  addressCluster Pa;
  addressRumah Pr;

  if (isListEmpty(L)) {
    cout << "Cabang Belum ada, silahkan di input!" << endl;
    return;
  } else {
    system("cls");
    cout << ".:: DELETE BOOKING RUMAH ::." << endl;
    printInfoListCabang(L);
    cout << "Masukan ID Cabang : ";
    cin >> cbg.id;
    Pi = findElmInduk(L,cbg);
    if (Pi == NULL) {
      cout << "Cabang Tidak Ada! Silakan input kembali!" << endl;
      return;
    } else {
      system("CLS");
      cout << "Nama Cabang : " << info(Pi).nama << endl;
      if (isClusterEmpty(Pi)) {
        cout << "Cabang ini belum memiliki Cluster, silakan input terlebih Dahulu!" << endl;
        return;
      } else {
        printInfoCluster(L,Pi);
        cout << "Masukan Nama Cluster : ";
        cin >> cls.nama;
        Pa = findElmAnak(L,Pi,cls);
        if (Pa == NULL){
          cout << "Cluster Tidak Ada! Silakan input kembali!";
          return;
        }
        cout << "Nama Cabang : " << info(Pi).nama << endl;
        cout << "Nama Cluster : " << info(Pa).nama << endl;
        if (info(Pa).booking == 0) {
          cout << "Belum ada rumah yg dibooking pada cluster ini:)" << endl;
          return;
        } else {
          printInfoListBooking(L,Pi,Pa);
          cout << "== DELETE BOOKING RUMAH == " << endl;
          cout << "Masukan idPemesanan : ";
          cin >> rmh.idP;
          Pr = findElmRumah(L,Pi,Pa,rmh);
          if (Pr == NULL){
            cout << "Nomor Pemesanan Tidak ditemukan!";
            return;
          }
          cout << "Yakin ingin menghapus idPemesanan Rumah No." << info(Pr).idP << " : "  << info(Pr).nama << " (" << info(Pr).noktp << ") (y/n) : ";
          cin >> key;
          if ((key == 'y') or (key == 'Y')) {
            rmh = info(Pr);
            deleteDataRumah(L,Pi,Pa,Pr);
            info(Pa).booking--;
            cout << "idPemesanan Rumah No." << rmh.idP << " atas nama : " << rmh.nama << " (" << rmh.noktp <<") pada Cluster "<< info(Pa).nama <<" berhasil dihapus!" << endl;
          } else {
            cout << "Anda Tidak melakukan perubahan!" << endl;
          }
        }
      }
    }
  }
}

void data(ListInduk &L) {
  cabang cabang1,cabang2,cabang3;
  cluster cluster1,cluster2,cluster3;

  addressCabang P;

  cabang1.id   = 1;
  cabang1.nama = "The Royale Green";
  cabang1.kota = "Jakarta Selatan";
  cabang1.provinsi = "DKI Jakarta";
  P = alokasiInduk(cabang1);
  insertLastInduk(L,P);

  cabang2.id   = 2;
  cabang2.nama = "Unique Montana";
  cabang2.kota = "Bandung";
  cabang2.provinsi = "Jawa Barat";
  P = alokasiInduk(cabang2);
  insertLastInduk(L,P);

  cabang3.id   = 3;
  cabang3.nama = "Tugu Residence";
  cabang3.kota = "Yogyakarta";
  cabang3.provinsi = "DI Yogyakarta";
  P = alokasiInduk(cabang3);
  insertLastInduk(L,P);
}

void createList(ListInduk &L) {
  first(L) = NULL;
  last(L) = NULL;
}

addressCabang alokasiInduk(infotypeCabang x) {
  addressCabang P = new ElmListCabang;
  info(P) = x;
  next(P) = NULL;
  prev(P) = NULL;
  anak(P) = NULL;
  return P;
}

addressCluster alokasiAnak(infotypeCluster x) {
  addressCluster P = new ElmListCluster;
  prev(P) = NULL;
  info(P) = x;
  rumah(P) = NULL;
  next(P) = NULL;
  return P;
}

addressRumah alokasiRumah(infotypeRumah x) {
  addressRumah P = new ElmListRumah;
  prev(P) = NULL;
  info(P) = x;
  next(P) = NULL;
  return P;
}

void dealokasiInduk(addressCabang &P) {
  delete P;
}

void dealokasiAnak(addressCluster &P) {
  delete P;
}

void dealokasiRumah(addressRumah &P) {
  delete P;
}

void insertFirstInduk(ListInduk &L, addressCabang P) {
  if (first(L) == NULL) {
    first(L) = P;
    last(L) = P;
    anak(first(L)) = NULL;
    next(last(L)) = first(L);
    prev(first(L)) = last(L);
  } else {
    next(P) = first(L);
    prev(first(L)) = P;
    first(L) = P;
    next(last(L)) = first(L);
    prev(first(L)) = last(L);
  }
}

void insertFirstAnak(ListInduk &L, addressCabang Pi, addressCluster Pa) {
  if(anak(Pi) == NULL){
    anak(Pi) = Pa;
  } else {
    next(Pa) = anak(Pi);
    prev(anak(Pi)) = Pa;
    anak(Pi) = Pa;
  }
}

void insertAfterInduk(ListInduk &L, addressCabang Prec, addressCabang P) {
  if (first(L) == NULL) {
    first(L) = P;
    last(L) = P;
    anak(first(L)) = NULL;
    next(last(L)) = first(L);
    prev(first(L)) = last(L);
  } else if (Prec == last(L)) {
    insertLastInduk(L,P);
  } else {
    prev(P) = Prec;
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    next(Prec) = P;
  }
}

void insertLastInduk(ListInduk &L, addressCabang P) {
  if (first(L) == NULL) {
    first(L) = P;
    last(L) = P;
    anak(first(L)) = NULL;
    next(last(L)) = first(L);
    prev(first(L)) = last(L);
  } else {
    next(last(L)) = P;
    prev(P) = last(L);
    last(L) = P;
    next(last(L)) = first(L);
    prev(first(L)) = last(L);
  }
}

void insertLastAnak(ListInduk &L, addressCabang Pi, addressCluster Pa) {
  if (anak(Pi) == NULL) {
    anak(Pi) = Pa;
  } else {
    addressCluster z = anak(Pi);
    while (next(z) != NULL) {
      z = next(z);
    }
    next(z) = Pa;
    prev(Pa) = z;
    next(Pa) = NULL;
  }
}

void insertLastRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah Pr) {
  if (rumah(Pa) == NULL) {
    rumah(Pa) = Pr;
  } else {
    addressRumah z = rumah(Pa);
    while (next(z) != NULL) {
      z = next(z);
    }
    next(z) = Pr;
    prev(Pr) = z;
    next(Pr) = NULL;
  }
}

addressCabang findElmInduk(ListInduk L, infotypeCabang x) {
  addressCabang P = first(L);
  do{
    if(info(P).id == x.id){
        return P;
    }
    P = next(P);
  } while (P != first(L));
  return NULL;
}

addressCluster findElmAnak(ListInduk L, addressCabang Pi ,infotypeCluster x) {
  addressCluster Pa =  anak(Pi);
  do{
    if(info(Pa).nama == x.nama){
      return Pa;
    }
    Pa = next(Pa);
  } while (Pa != NULL);
  return NULL;
}

addressRumah findElmRumah(ListInduk L, addressCabang Pi, addressCluster Pa, infotypeRumah x) {
  addressRumah Pr =  rumah(Pa);
  do{
    if(info(Pr).idP == x.idP){
      return Pr;
    }
    Pr = next(Pr);
  } while (Pr != NULL);
  return NULL;
}

void deleteFirstInduk(ListInduk &L, addressCabang &P) {
  if (first(L) == NULL) {
    cout << "List Kosong" << endl;
  } else if(first(L) == last(L)){
    P = first(L);
    first(L) = NULL;
    last(L) = NULL;
    dealokasiInduk(P);
  } else {
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
    next(last(L)) = first(L);
    prev(first(L)) = last(L);
    dealokasiInduk(P);
  }
}

void deleteFirstAnak(ListInduk &L, addressCabang Pi, addressCluster &Pa) {
  if (anak(Pi) == NULL) {
    cout << "Tidak Memiliki Anak" << endl;
  } else if(next(anak(Pi)) == NULL) {
    addressCluster z = anak(Pi);
    dealokasiAnak(z);
    anak(Pi) = NULL;
  } else {
    Pa = anak(Pi);
    anak(Pi) = next(Pa);
    next(Pa) = NULL;
    prev(anak(Pi)) = NULL;
  }
}

void deleteFirstRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah &Pr) {
  if (rumah(Pa) == NULL) {
    cout << "Tidak Memiliki Booking Rumah!" << endl;
  } else if(next(rumah(Pa)) == NULL) {
    addressRumah z = rumah(Pa);
    dealokasiRumah(z);
    rumah(Pa) = NULL;
  } else {
    Pr = rumah(Pa);
    rumah(Pa) = next(Pr);
    next(Pr) = NULL;
    prev(rumah(Pa)) = NULL;
  }
}

void deleteLastInduk(ListInduk &L, addressCabang &P) {
  if (first(L) == NULL) {
    cout << "List Kosong" << endl;
  } else if (first(L) == last(L)) {
    first(L) = NULL;
    last(L) = NULL;
  } else {
    P = last(L);
    last(L) = prev(P);
    next(last(L)) = first(L);
    prev(P) = NULL;
  }
}

void deleteLastAnak(ListInduk &L, addressCabang Pi, addressCluster &Pa) {
  if (anak(Pi) == NULL) {
    cout << "Tidak Memiliki Anak" << endl;
  } else if(next(anak(Pi)) == NULL) {
    addressCluster z = anak(Pi);
    dealokasiAnak(z);
    anak(Pi) = NULL;
  } else {
    addressCluster z = anak(Pi);
    while (next(z) != NULL) {
      z = next(z);
    }
    next(prev(z)) = NULL;
    prev(z) = NULL;
    dealokasiAnak(z);
  }
}

void deleteLastRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah &Pr) {
  if (rumah(Pa) == NULL) {
    cout << "Tidak Memiliki Anak" << endl;
  } else if(next(rumah(Pa)) == NULL) {
    addressRumah z = rumah(Pa);
    dealokasiRumah(z);
    rumah(Pa) = NULL;
  } else {
    addressRumah z = rumah(Pa);
    while (next(z) != NULL) {
      z = next(z);
    }
    next(prev(z)) = NULL;
    prev(z) = NULL;
    dealokasiRumah(z);
  }
}

void deleteAfterInduk(ListInduk &L, addressCabang Prec, addressCabang &P) {
  if (first(L) == NULL) {
    cout << "List Kosong" << endl;
  } else if ((first(L) == last(L)) || (Prec == last(L))) {
    cout << "Elemen Tidak Dapat Dihapus!" << endl;
  } else {
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
  }
}

void deleteAfterAnak(ListInduk &L, addressCluster Prec, addressCluster &Pa) {
  /*if (anak(Pa) == NULL) {
    cout << "Tidak memiliki anak!" << endl;
  } else */
  if (next(Pa) == NULL) {
    cout << "Elemen Tidak Dapat Dihapus!" << endl;
  } else {
    Pa = next(Prec);
    next(Prec) = next(Pa);
    prev(next(Pa)) = Prec;
    prev(Pa) = NULL;
    next(Pa) = NULL;
  }
}

void deleteAfterRumah(ListInduk &L, addressRumah Prec, addressRumah &Pr) {
  /*if (anak(Pa) == NULL) {
    cout << "Tidak memiliki anak!" << endl;
  } else */
  if (next(Pr) == NULL) {
    cout << "Elemen Tidak Dapat Dihapus!" << endl;
  } else {
    Pr = next(Prec);
    next(Prec) = next(Pr);
    prev(next(Pr)) = Prec;
    prev(Pr) = NULL;
    next(Pr) = NULL;
  }
}

void deleteData(ListInduk &L, addressCabang &P){
  addressCabang Prec;
  if (P != NULL) {
    if (P == first(L)) {
      deleteFirstInduk(L,P);
    } else if (P == last(L)) {
      deleteLastInduk(L,P);
    } else {
      Prec = prev(P);
      deleteAfterInduk(L,Prec,P);
    }
  }
}

void deleteDataAnak(ListInduk &L, addressCabang Pi, addressCluster &Pa){
  addressCluster Prec;
  if (Pa != NULL) {
    if (Pa == anak(Pi)) {
      deleteFirstAnak(L,Pi,Pa);
    } else if (next(Pa) == NULL) {
      deleteLastAnak(L,Pi,Pa);
    } else {
      Prec = prev(Pa);
      deleteAfterAnak(L,Prec,Pa);
    }
  }
}

void deleteDataRumah(ListInduk &L, addressCabang Pi, addressCluster Pa, addressRumah &Pr){
  addressRumah Prec;
  if (Pr != NULL) {
    if (Pr == rumah(Pa)) {
      deleteFirstRumah(L,Pi,Pa,Pr);
    } else if (next(Pr) == NULL) {
      deleteLastRumah(L,Pi,Pa,Pr);
    } else {
      Prec = prev(Pr);
      deleteAfterRumah(L,Prec,Pr);
    }
  }
}

void printInfoListCabang(ListInduk L) {
  if (first(L) == NULL) {
    cout << "List Kosong!" << endl;
  } else {
    addressCabang P = first(L);
    cout << "============================================" << endl;
    cout << "| ID \t | NAMA \t | KOTA \t | PRONVINSI \t |" << endl;
    cout << "============================================" << endl;
    do {
      cout << "| " << info(P).id << " \t | " << info(P).nama << " \t | ";
      cout << info(P).kota << " \t | " << info(P).provinsi << " \t | ";
      P = next(P);
      cout << endl;
    } while(P != first(L));
  }
}

void printInfo(ListInduk L) {
  int i = 0;
  addressCluster Pa;
  if (first(L) == NULL) {
    cout << "List Kosong!" << endl;
  } else {
    addressCabang P = first(L);
    cout << "=========================================================" << endl;
    cout << "| ID | NAMA \t | KOTA \t | PRONVINSI \t | CLUSTER \t |" << endl;
    cout << "=========================================================" << endl;
    do {
      cout << "| " << info(P).id << " | " << info(P).nama << " \t | ";
      cout << info(P).kota << " \t | " << info(P).provinsi << " \t | ";
      if (anak(P) != NULL){
        Pa = anak(P);
        do {
          i++;
          Pa = next(Pa);
        } while(Pa != NULL);
      }
      cout << i << " \t |" << endl;
      P = next(P);
    } while(P != first(L));
  }
}

void printInfoCluster(ListInduk L, addressCabang P) {
  if (anak(P) == NULL){
    cout << "Belum Memiliki Cluster! \nSilakan input terlebih dahulu :)" << endl;
  } else {
    int i = 1;
    addressCluster Pa = anak(P);
    cout << "====================================================================================" << endl;
    cout << "| NO | NAMA\t | LT\t| LB\t| KT\t| KM\t| KR\t| Lantai | Listrik | Harga | Booking |" << endl;
    cout << "====================================================================================" << endl;
    do {
      cout << "| " << i << " | " << info(Pa).nama << "\t | " << info(Pa).fitur.lt << "m2 \t";
      cout << "| " << info(Pa).fitur.lb << "m2 \t| " << info(Pa).fitur.kt << " + " << info(Pa).fitur.kp;
      cout << " | " << info(Pa).fitur.km << " \t| " << info(Pa).fitur.kr << " \t| "<< info(Pa).fitur.lantai;
      cout << " \t | " << info(Pa).fitur.listrik << " kWh   | " << info(Pa).harga << "\t  | " << info(Pa).booking << " of " << info(Pa).rmh << endl;
      i++;
      Pa = next(Pa);
    } while(Pa != NULL);
    cout << "====================================================================================" << endl;
    cout << endl;
  }
}


void printInfoListBooking(ListInduk L, addressCabang Pi, addressCluster Pa) {
  if(rumah(Pa) == NULL){
    cout << "Seluruh Rumah pada Cluster ini masih kosong, silakan di booking :)" << endl;
  } else {
    addressRumah Pr = rumah(Pa);
    cout << "CLUSTER " << info(Pa).nama << endl;
    cout << "===============================" << endl;
    cout << "| idPemesanan | NAMA\t | KTP\t|" << endl;
    cout << "===============================" << endl;
    do {
      cout << "| " << info(Pr).idP << " \t | " << info(Pr).nama << " \t | " << info(Pr).noktp << " \t | ";
      Pr = next(Pr);
      cout << endl;
    } while(Pr != NULL);
  }
}

bool isClusterEmpty(addressCabang Pi){
  if(anak(Pi) == NULL){
    return true;
  }
  return false;
}

bool isListEmpty(ListInduk L){
  if ((first(L) == NULL) && (last(L) == NULL)) {
    return true;
  }
  return false;
}
