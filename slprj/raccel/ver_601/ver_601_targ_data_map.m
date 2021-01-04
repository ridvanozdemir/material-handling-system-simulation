  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% rtP.bolge_sure_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.asan1_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.asan2_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.asan3_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.asan4_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.RandomNumber_Minimum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.RandomNumber_Maximum
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.RandomNumber_Seed
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.as_sure_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.sinyalizasyonaktif_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.sinyalizasyonaktifdegil_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.yuk_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.PulseGenerator_Amp
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.PulseGenerator_Period
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.PulseGenerator_Duty
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.PulseGenerator_PhaseDelay
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.son_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% rtB.fjz03whqln
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.lyuuaf4tgc
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.hlobqmbxfo
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.mmyhljpfw5
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.hdisprwwrk
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.meacvw3wyh
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.phezy3hqfx
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.dyv5pzuc22
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.l3ps3eg1j1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.cymbcyaldc
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.ibeao3ybvp
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.pt5pd0qwow
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.ozrcr5iiuo
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.btro1bqhix
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.emk21lju5k
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.oammtswjc1
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.gtqj3hxf4f
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 103;
      section.data(103)  = dumData; %prealloc
      
	  ;% rtDW.edcnujmoj4
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.agj0darvmg
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.dha2h4fzg4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.lxmk43h4lz
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.lbcota5ce1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hgtf5d3a2d
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.jz0awjjmoc
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.bkczy0k22h
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.gkgilqv5uk
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.hyn40d4jsd
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.fl5filc1dn
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.m3uontosom
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.ovn0rvfncf
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.gk030fyem1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.dbqcs5iwcz
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.ose2snqy5h
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.fuq40i2njw
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.bqdwzeq2un
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.nagfunplg2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.l2l0wvnhlk
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.fsdjwl2m1y
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.itxyfreth3
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.fcpu5l1c2n
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.hicdijuwpt
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.m4fcbiifke
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.dryt1of0li
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.pej45uuf3h
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.akc05dbtqw
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.hpiuttxiw3
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDW.gsqk3o01dv
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtDW.oszkfcwwh0
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtDW.haoggbus1r
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtDW.b0rkuyehww
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtDW.pvwjary3r4
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtDW.jx5ffpwvpg
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtDW.lwi0qugjmt
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtDW.duavnka4jn
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtDW.n1xsz5yxgo
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtDW.ldyhoi3th0
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtDW.aszdge2bj3
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtDW.inpsrydjdv
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtDW.a024nxxsmy
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtDW.ogcd4vjlyh
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtDW.onyupqnfyz
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtDW.dhgjnuwu0n
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtDW.om5rxt5ou1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtDW.mydlrme20h
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtDW.a5rmrgdlob
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtDW.exrpopdo5k
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtDW.fpjy00u0dg
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtDW.anokgjixfy
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% rtDW.kdkvsetk22
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% rtDW.moin2xmq0s
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% rtDW.hjcje1ohom
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% rtDW.ngmlzhmidv
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% rtDW.gmh5wpll4a
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% rtDW.pw2kiq0uix
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% rtDW.letkwdwdyo
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% rtDW.hxuj2eo4vo
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% rtDW.oj5qzckq3s
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% rtDW.bydzynpfs0
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% rtDW.h4x14diodv
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% rtDW.fdntrno1m0
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% rtDW.ka1uo1vch2
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% rtDW.amraafkuwm
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% rtDW.par4aypkbr
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% rtDW.gy0j0dfq0e
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% rtDW.li03emxpnp
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% rtDW.nxvvvn3icx
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% rtDW.jgql3zds1d
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% rtDW.ks5dixrmib
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% rtDW.agngepcllk
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% rtDW.dujirvadqc
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% rtDW.k3z1hawdyy
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% rtDW.aom1nwsm5u
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% rtDW.co2wqvk3mm
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% rtDW.dndx30bwcx
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% rtDW.dpja13yknf
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% rtDW.eidy4zo3j4
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% rtDW.bxadpccvt4
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% rtDW.ncxtztfcfw
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% rtDW.pzbesvy3oi
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% rtDW.hvmeczysda
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% rtDW.n43ygibiis
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% rtDW.aoj4uh13bn
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% rtDW.meo1exeijs
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% rtDW.ii1wiv1gpg
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% rtDW.ojv0czdmdm
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% rtDW.je1nwbypcu
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% rtDW.jz1r0f4m1o
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% rtDW.fssgd3gtc2
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
	  ;% rtDW.ke53mrcucn
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 91;
	
	  ;% rtDW.feyyhv1ejg
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 92;
	
	  ;% rtDW.nmcds41rle
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 93;
	
	  ;% rtDW.cv2caqkyag
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 94;
	
	  ;% rtDW.m1mjnutiuz
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 95;
	
	  ;% rtDW.ipxserfze1
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 96;
	
	  ;% rtDW.kh5cubf4hz
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 97;
	
	  ;% rtDW.is0ttfnzdk
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 98;
	
	  ;% rtDW.elursf1bof
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 99;
	
	  ;% rtDW.lvz4sjoyft
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 100;
	
	  ;% rtDW.mxh5c4jpih
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 101;
	
	  ;% rtDW.pgr4czd04f
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 102;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cc2apx5p5r.FilePtr
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.eehtav505d
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.kqu2dnmhtb
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% rtDW.ptm4o5g5f4
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.oduzdpbmb1
	  section.data(2).logicalSrcIdx = 107;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.k14hmzc4fq
	  section.data(3).logicalSrcIdx = 108;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.arawbmvmg3
	  section.data(4).logicalSrcIdx = 109;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.hjmhy1z112
	  section.data(5).logicalSrcIdx = 110;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.alka02fkkl
	  section.data(6).logicalSrcIdx = 111;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.pqpmykxnn5
	  section.data(7).logicalSrcIdx = 112;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.kwodmegsry
	  section.data(8).logicalSrcIdx = 113;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.jrqsouduhq
	  section.data(9).logicalSrcIdx = 114;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.fytwey2u0r
	  section.data(10).logicalSrcIdx = 115;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.au5vabt2mi
	  section.data(11).logicalSrcIdx = 116;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.d0meibhcuc
	  section.data(12).logicalSrcIdx = 117;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.gifcjoukwi
	  section.data(13).logicalSrcIdx = 118;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.kfz44rkzff
	  section.data(14).logicalSrcIdx = 119;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.nefya5plsy
	  section.data(15).logicalSrcIdx = 120;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.hf3qsopuk3
	  section.data(16).logicalSrcIdx = 121;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.o1seehfrez
	  section.data(17).logicalSrcIdx = 122;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.kzdd5niaph
	  section.data(18).logicalSrcIdx = 123;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.djm3iwzgxu
	  section.data(19).logicalSrcIdx = 124;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.pswmykzdp2
	  section.data(20).logicalSrcIdx = 125;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.kvj4ix352l
	  section.data(21).logicalSrcIdx = 126;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.cr2htc3uno
	  section.data(22).logicalSrcIdx = 127;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.itegyx3jit
	  section.data(23).logicalSrcIdx = 128;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.g35rdmxw02
	  section.data(24).logicalSrcIdx = 129;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.ekxosmzqx4
	  section.data(25).logicalSrcIdx = 130;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.onm520xe2d
	  section.data(26).logicalSrcIdx = 131;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.myjlktzzs4
	  section.data(27).logicalSrcIdx = 132;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.g5rtgto115
	  section.data(28).logicalSrcIdx = 133;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.pr3zhyc5rf
	  section.data(29).logicalSrcIdx = 134;
	  section.data(29).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.e0xe1ifujj.Count
	  section.data(1).logicalSrcIdx = 135;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fbk2lrgz23
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.mfpoxsltwf
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 60;
      section.data(60)  = dumData; %prealloc
      
	  ;% rtDW.kw0muczhpa
	  section.data(1).logicalSrcIdx = 138;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.l4obor5hlr
	  section.data(2).logicalSrcIdx = 139;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.mfdtmwnr1k
	  section.data(3).logicalSrcIdx = 140;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.oif5r1h22y
	  section.data(4).logicalSrcIdx = 141;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.fd4yepuw3r
	  section.data(5).logicalSrcIdx = 142;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hzd0mt5thm
	  section.data(6).logicalSrcIdx = 143;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.pdrmdwg3jy
	  section.data(7).logicalSrcIdx = 144;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.emslxlwkut
	  section.data(8).logicalSrcIdx = 145;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.bfyhmul5qc
	  section.data(9).logicalSrcIdx = 146;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.gdkpis41ue
	  section.data(10).logicalSrcIdx = 147;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.fibxlrf25e
	  section.data(11).logicalSrcIdx = 148;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.pa3b0d42cq
	  section.data(12).logicalSrcIdx = 149;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.ibbxyb4rh0
	  section.data(13).logicalSrcIdx = 150;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.kbkjspnsdq
	  section.data(14).logicalSrcIdx = 151;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.o1bk5bv40q
	  section.data(15).logicalSrcIdx = 152;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.mz2yvfypvs
	  section.data(16).logicalSrcIdx = 153;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.ncq15skmxi
	  section.data(17).logicalSrcIdx = 154;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.o0phaggmga
	  section.data(18).logicalSrcIdx = 155;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.eluhozh2mg
	  section.data(19).logicalSrcIdx = 156;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.owwx1zpbev
	  section.data(20).logicalSrcIdx = 157;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.dzgke5dtts
	  section.data(21).logicalSrcIdx = 158;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.nsceihis4p
	  section.data(22).logicalSrcIdx = 159;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.ieyrxl1u2b
	  section.data(23).logicalSrcIdx = 160;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.heqx2n2bs3
	  section.data(24).logicalSrcIdx = 161;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.gkrx454lti
	  section.data(25).logicalSrcIdx = 162;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.fy3nfeqxeh
	  section.data(26).logicalSrcIdx = 163;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.kftebazjtb
	  section.data(27).logicalSrcIdx = 164;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.e5d3vh5mtr
	  section.data(28).logicalSrcIdx = 165;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.am55xe0sw3
	  section.data(29).logicalSrcIdx = 166;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDW.n4yhk0zzjt
	  section.data(30).logicalSrcIdx = 167;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtDW.muqm3n4moh
	  section.data(31).logicalSrcIdx = 168;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtDW.kac1izqly2
	  section.data(32).logicalSrcIdx = 169;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtDW.k1gwjhv2mz
	  section.data(33).logicalSrcIdx = 170;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtDW.kmzoyidp5h
	  section.data(34).logicalSrcIdx = 171;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtDW.ftsj02ku3o
	  section.data(35).logicalSrcIdx = 172;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtDW.e2cyjfx3wk
	  section.data(36).logicalSrcIdx = 173;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtDW.old3xy41za
	  section.data(37).logicalSrcIdx = 174;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtDW.gxappx4nlx
	  section.data(38).logicalSrcIdx = 175;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtDW.b353cpbioc
	  section.data(39).logicalSrcIdx = 176;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtDW.fg2yv0b13x
	  section.data(40).logicalSrcIdx = 177;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtDW.drpukoqm3q
	  section.data(41).logicalSrcIdx = 178;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtDW.opbrwbl3ga
	  section.data(42).logicalSrcIdx = 179;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtDW.kxrjhxe0ou
	  section.data(43).logicalSrcIdx = 180;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtDW.f0utxalh2x
	  section.data(44).logicalSrcIdx = 181;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtDW.pqcjonzr4v
	  section.data(45).logicalSrcIdx = 182;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtDW.o2wxdztuaa
	  section.data(46).logicalSrcIdx = 183;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtDW.ni4lgririy
	  section.data(47).logicalSrcIdx = 184;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtDW.cglv5jdbhe
	  section.data(48).logicalSrcIdx = 185;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtDW.mtmrtegtf1
	  section.data(49).logicalSrcIdx = 186;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtDW.fussrez5qj
	  section.data(50).logicalSrcIdx = 187;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtDW.j1ugige0vf
	  section.data(51).logicalSrcIdx = 188;
	  section.data(51).dtTransOffset = 50;
	
	  ;% rtDW.mmakc333ez
	  section.data(52).logicalSrcIdx = 189;
	  section.data(52).dtTransOffset = 51;
	
	  ;% rtDW.irnttpsjl3
	  section.data(53).logicalSrcIdx = 190;
	  section.data(53).dtTransOffset = 52;
	
	  ;% rtDW.cghs2fki2b
	  section.data(54).logicalSrcIdx = 191;
	  section.data(54).dtTransOffset = 53;
	
	  ;% rtDW.gp4cddax2b
	  section.data(55).logicalSrcIdx = 192;
	  section.data(55).dtTransOffset = 54;
	
	  ;% rtDW.hosixhznoe
	  section.data(56).logicalSrcIdx = 193;
	  section.data(56).dtTransOffset = 55;
	
	  ;% rtDW.kevtffqy21
	  section.data(57).logicalSrcIdx = 194;
	  section.data(57).dtTransOffset = 56;
	
	  ;% rtDW.c55dplmdoj
	  section.data(58).logicalSrcIdx = 195;
	  section.data(58).dtTransOffset = 57;
	
	  ;% rtDW.o3f5tl0sya
	  section.data(59).logicalSrcIdx = 196;
	  section.data(59).dtTransOffset = 58;
	
	  ;% rtDW.g4tcltg5yk
	  section.data(60).logicalSrcIdx = 197;
	  section.data(60).dtTransOffset = 59;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2863782131;
  targMap.checksum1 = 2862256862;
  targMap.checksum2 = 4011033938;
  targMap.checksum3 = 1389313984;

