
def readRandomBin():
    try:
        with open("../random_list.bin", "rb") as file:
            array_bytes = file.read()
    except:
        print("Error al abrir")
        exit(1)

    num = len(array_bytes) // 4
    array_int = [int.from_bytes(array_bytes[i:i+4], byteorder='little') for i in range(0, len(array_bytes), 4)]

    return num, array_int

if __name__ == "__main__":
    num, array_int = readRandomBin()

    for i in range(num):
        value = array_int[i] % 1000
        match value:
            case 0:
                pass
            case 1:
                pass
            case 2:
                pass
            case 3:
                pass
            case 4:
                pass
            case 5:
                pass
            case 6:
                pass
            case 7:
                pass
            case 8:
                pass
            case 9:
                pass
            case 10:
                pass
            case 11:
                pass
            case 12:
                pass
            case 13:
                pass
            case 14:
                pass
            case 15:
                pass
            case 16:
                pass
            case 17:
                pass
            case 18:
                pass
            case 19:
                pass
            case 20:
                pass
            case 21:
                pass
            case 22:
                pass
            case 23:
                pass
            case 24:
                pass
            case 25:
                pass
            case 26:
                pass
            case 27:
                pass
            case 28:
                pass
            case 29:
                pass
            case 30:
                pass
            case 31:
                pass
            case 32:
                pass
            case 33:
                pass
            case 34:
                pass
            case 35:
                pass
            case 36:
                pass
            case 37:
                pass
            case 38:
                pass
            case 39:
                pass
            case 40:
                pass
            case 41:
                pass
            case 42:
                pass
            case 43:
                pass
            case 44:
                pass
            case 45:
                pass
            case 46:
                pass
            case 47:
                pass
            case 48:
                pass
            case 49:
                pass
            case 50:
                pass
            case 51:
                pass
            case 52:
                pass
            case 53:
                pass
            case 54:
                pass
            case 55:
                pass
            case 56:
                pass
            case 57:
                pass
            case 58:
                pass
            case 59:
                pass
            case 60:
                pass
            case 61:
                pass
            case 62:
                pass
            case 63:
                pass
            case 64:
                pass
            case 65:
                pass
            case 66:
                pass
            case 67:
                pass
            case 68:
                pass
            case 69:
                pass
            case 70:
                pass
            case 71:
                pass
            case 72:
                pass
            case 73:
                pass
            case 74:
                pass
            case 75:
                pass
            case 76:
                pass
            case 77:
                pass
            case 78:
                pass
            case 79:
                pass
            case 80:
                pass
            case 81:
                pass
            case 82:
                pass
            case 83:
                pass
            case 84:
                pass
            case 85:
                pass
            case 86:
                pass
            case 87:
                pass
            case 88:
                pass
            case 89:
                pass
            case 90:
                pass
            case 91:
                pass
            case 92:
                pass
            case 93:
                pass
            case 94:
                pass
            case 95:
                pass
            case 96:
                pass
            case 97:
                pass
            case 98:
                pass
            case 99:
                pass
            case 100:
                pass
            case 101:
                pass
            case 102:
                pass
            case 103:
                pass
            case 104:
                pass
            case 105:
                pass
            case 106:
                pass
            case 107:
                pass
            case 108:
                pass
            case 109:
                pass
            case 110:
                pass
            case 111:
                pass
            case 112:
                pass
            case 113:
                pass
            case 114:
                pass
            case 115:
                pass
            case 116:
                pass
            case 117:
                pass
            case 118:
                pass
            case 119:
                pass
            case 120:
                pass
            case 121:
                pass
            case 122:
                pass
            case 123:
                pass
            case 124:
                pass
            case 125:
                pass
            case 126:
                pass
            case 127:
                pass
            case 128:
                pass
            case 129:
                pass
            case 130:
                pass
            case 131:
                pass
            case 132:
                pass
            case 133:
                pass
            case 134:
                pass
            case 135:
                pass
            case 136:
                pass
            case 137:
                pass
            case 138:
                pass
            case 139:
                pass
            case 140:
                pass
            case 141:
                pass
            case 142:
                pass
            case 143:
                pass
            case 144:
                pass
            case 145:
                pass
            case 146:
                pass
            case 147:
                pass
            case 148:
                pass
            case 149:
                pass
            case 150:
                pass
            case 151:
                pass
            case 152:
                pass
            case 153:
                pass
            case 154:
                pass
            case 155:
                pass
            case 156:
                pass
            case 157:
                pass
            case 158:
                pass
            case 159:
                pass
            case 160:
                pass
            case 161:
                pass
            case 162:
                pass
            case 163:
                pass
            case 164:
                pass
            case 165:
                pass
            case 166:
                pass
            case 167:
                pass
            case 168:
                pass
            case 169:
                pass
            case 170:
                pass
            case 171:
                pass
            case 172:
                pass
            case 173:
                pass
            case 174:
                pass
            case 175:
                pass
            case 176:
                pass
            case 177:
                pass
            case 178:
                pass
            case 179:
                pass
            case 180:
                pass
            case 181:
                pass
            case 182:
                pass
            case 183:
                pass
            case 184:
                pass
            case 185:
                pass
            case 186:
                pass
            case 187:
                pass
            case 188:
                pass
            case 189:
                pass
            case 190:
                pass
            case 191:
                pass
            case 192:
                pass
            case 193:
                pass
            case 194:
                pass
            case 195:
                pass
            case 196:
                pass
            case 197:
                pass
            case 198:
                pass
            case 199:
                pass
            case 200:
                pass
            case 201:
                pass
            case 202:
                pass
            case 203:
                pass
            case 204:
                pass
            case 205:
                pass
            case 206:
                pass
            case 207:
                pass
            case 208:
                pass
            case 209:
                pass
            case 210:
                pass
            case 211:
                pass
            case 212:
                pass
            case 213:
                pass
            case 214:
                pass
            case 215:
                pass
            case 216:
                pass
            case 217:
                pass
            case 218:
                pass
            case 219:
                pass
            case 220:
                pass
            case 221:
                pass
            case 222:
                pass
            case 223:
                pass
            case 224:
                pass
            case 225:
                pass
            case 226:
                pass
            case 227:
                pass
            case 228:
                pass
            case 229:
                pass
            case 230:
                pass
            case 231:
                pass
            case 232:
                pass
            case 233:
                pass
            case 234:
                pass
            case 235:
                pass
            case 236:
                pass
            case 237:
                pass
            case 238:
                pass
            case 239:
                pass
            case 240:
                pass
            case 241:
                pass
            case 242:
                pass
            case 243:
                pass
            case 244:
                pass
            case 245:
                pass
            case 246:
                pass
            case 247:
                pass
            case 248:
                pass
            case 249:
                pass
            case 250:
                pass
            case 251:
                pass
            case 252:
                pass
            case 253:
                pass
            case 254:
                pass
            case 255:
                pass
            case 256:
                pass
            case 257:
                pass
            case 258:
                pass
            case 259:
                pass
            case 260:
                pass
            case 261:
                pass
            case 262:
                pass
            case 263:
                pass
            case 264:
                pass
            case 265:
                pass
            case 266:
                pass
            case 267:
                pass
            case 268:
                pass
            case 269:
                pass
            case 270:
                pass
            case 271:
                pass
            case 272:
                pass
            case 273:
                pass
            case 274:
                pass
            case 275:
                pass
            case 276:
                pass
            case 277:
                pass
            case 278:
                pass
            case 279:
                pass
            case 280:
                pass
            case 281:
                pass
            case 282:
                pass
            case 283:
                pass
            case 284:
                pass
            case 285:
                pass
            case 286:
                pass
            case 287:
                pass
            case 288:
                pass
            case 289:
                pass
            case 290:
                pass
            case 291:
                pass
            case 292:
                pass
            case 293:
                pass
            case 294:
                pass
            case 295:
                pass
            case 296:
                pass
            case 297:
                pass
            case 298:
                pass
            case 299:
                pass
            case 300:
                pass
            case 301:
                pass
            case 302:
                pass
            case 303:
                pass
            case 304:
                pass
            case 305:
                pass
            case 306:
                pass
            case 307:
                pass
            case 308:
                pass
            case 309:
                pass
            case 310:
                pass
            case 311:
                pass
            case 312:
                pass
            case 313:
                pass
            case 314:
                pass
            case 315:
                pass
            case 316:
                pass
            case 317:
                pass
            case 318:
                pass
            case 319:
                pass
            case 320:
                pass
            case 321:
                pass
            case 322:
                pass
            case 323:
                pass
            case 324:
                pass
            case 325:
                pass
            case 326:
                pass
            case 327:
                pass
            case 328:
                pass
            case 329:
                pass
            case 330:
                pass
            case 331:
                pass
            case 332:
                pass
            case 333:
                pass
            case 334:
                pass
            case 335:
                pass
            case 336:
                pass
            case 337:
                pass
            case 338:
                pass
            case 339:
                pass
            case 340:
                pass
            case 341:
                pass
            case 342:
                pass
            case 343:
                pass
            case 344:
                pass
            case 345:
                pass
            case 346:
                pass
            case 347:
                pass
            case 348:
                pass
            case 349:
                pass
            case 350:
                pass
            case 351:
                pass
            case 352:
                pass
            case 353:
                pass
            case 354:
                pass
            case 355:
                pass
            case 356:
                pass
            case 357:
                pass
            case 358:
                pass
            case 359:
                pass
            case 360:
                pass
            case 361:
                pass
            case 362:
                pass
            case 363:
                pass
            case 364:
                pass
            case 365:
                pass
            case 366:
                pass
            case 367:
                pass
            case 368:
                pass
            case 369:
                pass
            case 370:
                pass
            case 371:
                pass
            case 372:
                pass
            case 373:
                pass
            case 374:
                pass
            case 375:
                pass
            case 376:
                pass
            case 377:
                pass
            case 378:
                pass
            case 379:
                pass
            case 380:
                pass
            case 381:
                pass
            case 382:
                pass
            case 383:
                pass
            case 384:
                pass
            case 385:
                pass
            case 386:
                pass
            case 387:
                pass
            case 388:
                pass
            case 389:
                pass
            case 390:
                pass
            case 391:
                pass
            case 392:
                pass
            case 393:
                pass
            case 394:
                pass
            case 395:
                pass
            case 396:
                pass
            case 397:
                pass
            case 398:
                pass
            case 399:
                pass
            case 400:
                pass
            case 401:
                pass
            case 402:
                pass
            case 403:
                pass
            case 404:
                pass
            case 405:
                pass
            case 406:
                pass
            case 407:
                pass
            case 408:
                pass
            case 409:
                pass
            case 410:
                pass
            case 411:
                pass
            case 412:
                pass
            case 413:
                pass
            case 414:
                pass
            case 415:
                pass
            case 416:
                pass
            case 417:
                pass
            case 418:
                pass
            case 419:
                pass
            case 420:
                pass
            case 421:
                pass
            case 422:
                pass
            case 423:
                pass
            case 424:
                pass
            case 425:
                pass
            case 426:
                pass
            case 427:
                pass
            case 428:
                pass
            case 429:
                pass
            case 430:
                pass
            case 431:
                pass
            case 432:
                pass
            case 433:
                pass
            case 434:
                pass
            case 435:
                pass
            case 436:
                pass
            case 437:
                pass
            case 438:
                pass
            case 439:
                pass
            case 440:
                pass
            case 441:
                pass
            case 442:
                pass
            case 443:
                pass
            case 444:
                pass
            case 445:
                pass
            case 446:
                pass
            case 447:
                pass
            case 448:
                pass
            case 449:
                pass
            case 450:
                pass
            case 451:
                pass
            case 452:
                pass
            case 453:
                pass
            case 454:
                pass
            case 455:
                pass
            case 456:
                pass
            case 457:
                pass
            case 458:
                pass
            case 459:
                pass
            case 460:
                pass
            case 461:
                pass
            case 462:
                pass
            case 463:
                pass
            case 464:
                pass
            case 465:
                pass
            case 466:
                pass
            case 467:
                pass
            case 468:
                pass
            case 469:
                pass
            case 470:
                pass
            case 471:
                pass
            case 472:
                pass
            case 473:
                pass
            case 474:
                pass
            case 475:
                pass
            case 476:
                pass
            case 477:
                pass
            case 478:
                pass
            case 479:
                pass
            case 480:
                pass
            case 481:
                pass
            case 482:
                pass
            case 483:
                pass
            case 484:
                pass
            case 485:
                pass
            case 486:
                pass
            case 487:
                pass
            case 488:
                pass
            case 489:
                pass
            case 490:
                pass
            case 491:
                pass
            case 492:
                pass
            case 493:
                pass
            case 494:
                pass
            case 495:
                pass
            case 496:
                pass
            case 497:
                pass
            case 498:
                pass
            case 499:
                pass
            case 500:
                pass
            case 501:
                pass
            case 502:
                pass
            case 503:
                pass
            case 504:
                pass
            case 505:
                pass
            case 506:
                pass
            case 507:
                pass
            case 508:
                pass
            case 509:
                pass
            case 510:
                pass
            case 511:
                pass
            case 512:
                pass
            case 513:
                pass
            case 514:
                pass
            case 515:
                pass
            case 516:
                pass
            case 517:
                pass
            case 518:
                pass
            case 519:
                pass
            case 520:
                pass
            case 521:
                pass
            case 522:
                pass
            case 523:
                pass
            case 524:
                pass
            case 525:
                pass
            case 526:
                pass
            case 527:
                pass
            case 528:
                pass
            case 529:
                pass
            case 530:
                pass
            case 531:
                pass
            case 532:
                pass
            case 533:
                pass
            case 534:
                pass
            case 535:
                pass
            case 536:
                pass
            case 537:
                pass
            case 538:
                pass
            case 539:
                pass
            case 540:
                pass
            case 541:
                pass
            case 542:
                pass
            case 543:
                pass
            case 544:
                pass
            case 545:
                pass
            case 546:
                pass
            case 547:
                pass
            case 548:
                pass
            case 549:
                pass
            case 550:
                pass
            case 551:
                pass
            case 552:
                pass
            case 553:
                pass
            case 554:
                pass
            case 555:
                pass
            case 556:
                pass
            case 557:
                pass
            case 558:
                pass
            case 559:
                pass
            case 560:
                pass
            case 561:
                pass
            case 562:
                pass
            case 563:
                pass
            case 564:
                pass
            case 565:
                pass
            case 566:
                pass
            case 567:
                pass
            case 568:
                pass
            case 569:
                pass
            case 570:
                pass
            case 571:
                pass
            case 572:
                pass
            case 573:
                pass
            case 574:
                pass
            case 575:
                pass
            case 576:
                pass
            case 577:
                pass
            case 578:
                pass
            case 579:
                pass
            case 580:
                pass
            case 581:
                pass
            case 582:
                pass
            case 583:
                pass
            case 584:
                pass
            case 585:
                pass
            case 586:
                pass
            case 587:
                pass
            case 588:
                pass
            case 589:
                pass
            case 590:
                pass
            case 591:
                pass
            case 592:
                pass
            case 593:
                pass
            case 594:
                pass
            case 595:
                pass
            case 596:
                pass
            case 597:
                pass
            case 598:
                pass
            case 599:
                pass
            case 600:
                pass
            case 601:
                pass
            case 602:
                pass
            case 603:
                pass
            case 604:
                pass
            case 605:
                pass
            case 606:
                pass
            case 607:
                pass
            case 608:
                pass
            case 609:
                pass
            case 610:
                pass
            case 611:
                pass
            case 612:
                pass
            case 613:
                pass
            case 614:
                pass
            case 615:
                pass
            case 616:
                pass
            case 617:
                pass
            case 618:
                pass
            case 619:
                pass
            case 620:
                pass
            case 621:
                pass
            case 622:
                pass
            case 623:
                pass
            case 624:
                pass
            case 625:
                pass
            case 626:
                pass
            case 627:
                pass
            case 628:
                pass
            case 629:
                pass
            case 630:
                pass
            case 631:
                pass
            case 632:
                pass
            case 633:
                pass
            case 634:
                pass
            case 635:
                pass
            case 636:
                pass
            case 637:
                pass
            case 638:
                pass
            case 639:
                pass
            case 640:
                pass
            case 641:
                pass
            case 642:
                pass
            case 643:
                pass
            case 644:
                pass
            case 645:
                pass
            case 646:
                pass
            case 647:
                pass
            case 648:
                pass
            case 649:
                pass
            case 650:
                pass
            case 651:
                pass
            case 652:
                pass
            case 653:
                pass
            case 654:
                pass
            case 655:
                pass
            case 656:
                pass
            case 657:
                pass
            case 658:
                pass
            case 659:
                pass
            case 660:
                pass
            case 661:
                pass
            case 662:
                pass
            case 663:
                pass
            case 664:
                pass
            case 665:
                pass
            case 666:
                pass
            case 667:
                pass
            case 668:
                pass
            case 669:
                pass
            case 670:
                pass
            case 671:
                pass
            case 672:
                pass
            case 673:
                pass
            case 674:
                pass
            case 675:
                pass
            case 676:
                pass
            case 677:
                pass
            case 678:
                pass
            case 679:
                pass
            case 680:
                pass
            case 681:
                pass
            case 682:
                pass
            case 683:
                pass
            case 684:
                pass
            case 685:
                pass
            case 686:
                pass
            case 687:
                pass
            case 688:
                pass
            case 689:
                pass
            case 690:
                pass
            case 691:
                pass
            case 692:
                pass
            case 693:
                pass
            case 694:
                pass
            case 695:
                pass
            case 696:
                pass
            case 697:
                pass
            case 698:
                pass
            case 699:
                pass
            case 700:
                pass
            case 701:
                pass
            case 702:
                pass
            case 703:
                pass
            case 704:
                pass
            case 705:
                pass
            case 706:
                pass
            case 707:
                pass
            case 708:
                pass
            case 709:
                pass
            case 710:
                pass
            case 711:
                pass
            case 712:
                pass
            case 713:
                pass
            case 714:
                pass
            case 715:
                pass
            case 716:
                pass
            case 717:
                pass
            case 718:
                pass
            case 719:
                pass
            case 720:
                pass
            case 721:
                pass
            case 722:
                pass
            case 723:
                pass
            case 724:
                pass
            case 725:
                pass
            case 726:
                pass
            case 727:
                pass
            case 728:
                pass
            case 729:
                pass
            case 730:
                pass
            case 731:
                pass
            case 732:
                pass
            case 733:
                pass
            case 734:
                pass
            case 735:
                pass
            case 736:
                pass
            case 737:
                pass
            case 738:
                pass
            case 739:
                pass
            case 740:
                pass
            case 741:
                pass
            case 742:
                pass
            case 743:
                pass
            case 744:
                pass
            case 745:
                pass
            case 746:
                pass
            case 747:
                pass
            case 748:
                pass
            case 749:
                pass
            case 750:
                pass
            case 751:
                pass
            case 752:
                pass
            case 753:
                pass
            case 754:
                pass
            case 755:
                pass
            case 756:
                pass
            case 757:
                pass
            case 758:
                pass
            case 759:
                pass
            case 760:
                pass
            case 761:
                pass
            case 762:
                pass
            case 763:
                pass
            case 764:
                pass
            case 765:
                pass
            case 766:
                pass
            case 767:
                pass
            case 768:
                pass
            case 769:
                pass
            case 770:
                pass
            case 771:
                pass
            case 772:
                pass
            case 773:
                pass
            case 774:
                pass
            case 775:
                pass
            case 776:
                pass
            case 777:
                pass
            case 778:
                pass
            case 779:
                pass
            case 780:
                pass
            case 781:
                pass
            case 782:
                pass
            case 783:
                pass
            case 784:
                pass
            case 785:
                pass
            case 786:
                pass
            case 787:
                pass
            case 788:
                pass
            case 789:
                pass
            case 790:
                pass
            case 791:
                pass
            case 792:
                pass
            case 793:
                pass
            case 794:
                pass
            case 795:
                pass
            case 796:
                pass
            case 797:
                pass
            case 798:
                pass
            case 799:
                pass
            case 800:
                pass
            case 801:
                pass
            case 802:
                pass
            case 803:
                pass
            case 804:
                pass
            case 805:
                pass
            case 806:
                pass
            case 807:
                pass
            case 808:
                pass
            case 809:
                pass
            case 810:
                pass
            case 811:
                pass
            case 812:
                pass
            case 813:
                pass
            case 814:
                pass
            case 815:
                pass
            case 816:
                pass
            case 817:
                pass
            case 818:
                pass
            case 819:
                pass
            case 820:
                pass
            case 821:
                pass
            case 822:
                pass
            case 823:
                pass
            case 824:
                pass
            case 825:
                pass
            case 826:
                pass
            case 827:
                pass
            case 828:
                pass
            case 829:
                pass
            case 830:
                pass
            case 831:
                pass
            case 832:
                pass
            case 833:
                pass
            case 834:
                pass
            case 835:
                pass
            case 836:
                pass
            case 837:
                pass
            case 838:
                pass
            case 839:
                pass
            case 840:
                pass
            case 841:
                pass
            case 842:
                pass
            case 843:
                pass
            case 844:
                pass
            case 845:
                pass
            case 846:
                pass
            case 847:
                pass
            case 848:
                pass
            case 849:
                pass
            case 850:
                pass
            case 851:
                pass
            case 852:
                pass
            case 853:
                pass
            case 854:
                pass
            case 855:
                pass
            case 856:
                pass
            case 857:
                pass
            case 858:
                pass
            case 859:
                pass
            case 860:
                pass
            case 861:
                pass
            case 862:
                pass
            case 863:
                pass
            case 864:
                pass
            case 865:
                pass
            case 866:
                pass
            case 867:
                pass
            case 868:
                pass
            case 869:
                pass
            case 870:
                pass
            case 871:
                pass
            case 872:
                pass
            case 873:
                pass
            case 874:
                pass
            case 875:
                pass
            case 876:
                pass
            case 877:
                pass
            case 878:
                pass
            case 879:
                pass
            case 880:
                pass
            case 881:
                pass
            case 882:
                pass
            case 883:
                pass
            case 884:
                pass
            case 885:
                pass
            case 886:
                pass
            case 887:
                pass
            case 888:
                pass
            case 889:
                pass
            case 890:
                pass
            case 891:
                pass
            case 892:
                pass
            case 893:
                pass
            case 894:
                pass
            case 895:
                pass
            case 896:
                pass
            case 897:
                pass
            case 898:
                pass
            case 899:
                pass
            case 900:
                pass
            case 901:
                pass
            case 902:
                pass
            case 903:
                pass
            case 904:
                pass
            case 905:
                pass
            case 906:
                pass
            case 907:
                pass
            case 908:
                pass
            case 909:
                pass
            case 910:
                pass
            case 911:
                pass
            case 912:
                pass
            case 913:
                pass
            case 914:
                pass
            case 915:
                pass
            case 916:
                pass
            case 917:
                pass
            case 918:
                pass
            case 919:
                pass
            case 920:
                pass
            case 921:
                pass
            case 922:
                pass
            case 923:
                pass
            case 924:
                pass
            case 925:
                pass
            case 926:
                pass
            case 927:
                pass
            case 928:
                pass
            case 929:
                pass
            case 930:
                pass
            case 931:
                pass
            case 932:
                pass
            case 933:
                pass
            case 934:
                pass
            case 935:
                pass
            case 936:
                pass
            case 937:
                pass
            case 938:
                pass
            case 939:
                pass
            case 940:
                pass
            case 941:
                pass
            case 942:
                pass
            case 943:
                pass
            case 944:
                pass
            case 945:
                pass
            case 946:
                pass
            case 947:
                pass
            case 948:
                pass
            case 949:
                pass
            case 950:
                pass
            case 951:
                pass
            case 952:
                pass
            case 953:
                pass
            case 954:
                pass
            case 955:
                pass
            case 956:
                pass
            case 957:
                pass
            case 958:
                pass
            case 959:
                pass
            case 960:
                pass
            case 961:
                pass
            case 962:
                pass
            case 963:
                pass
            case 964:
                pass
            case 965:
                pass
            case 966:
                pass
            case 967:
                pass
            case 968:
                pass
            case 969:
                pass
            case 970:
                pass
            case 971:
                pass
            case 972:
                pass
            case 973:
                pass
            case 974:
                pass
            case 975:
                pass
            case 976:
                pass
            case 977:
                pass
            case 978:
                pass
            case 979:
                pass
            case 980:
                pass
            case 981:
                pass
            case 982:
                pass
            case 983:
                pass
            case 984:
                pass
            case 985:
                pass
            case 986:
                pass
            case 987:
                pass
            case 988:
                pass
            case 989:
                pass
            case 990:
                pass
            case 991:
                pass
            case 992:
                pass
            case 993:
                pass
            case 994:
                pass
            case 995:
                pass
            case 996:
                pass
            case 997:
                pass
            case 998:
                pass
            case 999:
                pass
            case _:
                pass
