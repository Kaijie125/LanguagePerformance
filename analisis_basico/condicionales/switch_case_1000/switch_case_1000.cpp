
#include <iostream>
#include <fstream>
int readRandomBin(int *&array_int, int &num){
    std::ifstream file("../random_list.bin", std::ios::binary);
    if (!file) {
        return 1;
    }

    file.seekg(0, std::ios::end);
    long file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    num = file_size / sizeof(int);
    array_int = new int[num];

    file.read(reinterpret_cast<char*>(array_int), file_size);

    file.close();
    return 0;
}

int main() {
    
    int num;
    int *array_int;

    if (readRandomBin(array_int, num) != 0) {
        std::cerr << "Error al abrir" << std::endl;
        return 1;
    }

    for (int i = 0; i < num; i++){
        int value = array_int[i] % 1000;
        switch (value) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;
            case 21:
                break;
            case 22:
                break;
            case 23:
                break;
            case 24:
                break;
            case 25:
                break;
            case 26:
                break;
            case 27:
                break;
            case 28:
                break;
            case 29:
                break;
            case 30:
                break;
            case 31:
                break;
            case 32:
                break;
            case 33:
                break;
            case 34:
                break;
            case 35:
                break;
            case 36:
                break;
            case 37:
                break;
            case 38:
                break;
            case 39:
                break;
            case 40:
                break;
            case 41:
                break;
            case 42:
                break;
            case 43:
                break;
            case 44:
                break;
            case 45:
                break;
            case 46:
                break;
            case 47:
                break;
            case 48:
                break;
            case 49:
                break;
            case 50:
                break;
            case 51:
                break;
            case 52:
                break;
            case 53:
                break;
            case 54:
                break;
            case 55:
                break;
            case 56:
                break;
            case 57:
                break;
            case 58:
                break;
            case 59:
                break;
            case 60:
                break;
            case 61:
                break;
            case 62:
                break;
            case 63:
                break;
            case 64:
                break;
            case 65:
                break;
            case 66:
                break;
            case 67:
                break;
            case 68:
                break;
            case 69:
                break;
            case 70:
                break;
            case 71:
                break;
            case 72:
                break;
            case 73:
                break;
            case 74:
                break;
            case 75:
                break;
            case 76:
                break;
            case 77:
                break;
            case 78:
                break;
            case 79:
                break;
            case 80:
                break;
            case 81:
                break;
            case 82:
                break;
            case 83:
                break;
            case 84:
                break;
            case 85:
                break;
            case 86:
                break;
            case 87:
                break;
            case 88:
                break;
            case 89:
                break;
            case 90:
                break;
            case 91:
                break;
            case 92:
                break;
            case 93:
                break;
            case 94:
                break;
            case 95:
                break;
            case 96:
                break;
            case 97:
                break;
            case 98:
                break;
            case 99:
                break;
            case 100:
                break;
            case 101:
                break;
            case 102:
                break;
            case 103:
                break;
            case 104:
                break;
            case 105:
                break;
            case 106:
                break;
            case 107:
                break;
            case 108:
                break;
            case 109:
                break;
            case 110:
                break;
            case 111:
                break;
            case 112:
                break;
            case 113:
                break;
            case 114:
                break;
            case 115:
                break;
            case 116:
                break;
            case 117:
                break;
            case 118:
                break;
            case 119:
                break;
            case 120:
                break;
            case 121:
                break;
            case 122:
                break;
            case 123:
                break;
            case 124:
                break;
            case 125:
                break;
            case 126:
                break;
            case 127:
                break;
            case 128:
                break;
            case 129:
                break;
            case 130:
                break;
            case 131:
                break;
            case 132:
                break;
            case 133:
                break;
            case 134:
                break;
            case 135:
                break;
            case 136:
                break;
            case 137:
                break;
            case 138:
                break;
            case 139:
                break;
            case 140:
                break;
            case 141:
                break;
            case 142:
                break;
            case 143:
                break;
            case 144:
                break;
            case 145:
                break;
            case 146:
                break;
            case 147:
                break;
            case 148:
                break;
            case 149:
                break;
            case 150:
                break;
            case 151:
                break;
            case 152:
                break;
            case 153:
                break;
            case 154:
                break;
            case 155:
                break;
            case 156:
                break;
            case 157:
                break;
            case 158:
                break;
            case 159:
                break;
            case 160:
                break;
            case 161:
                break;
            case 162:
                break;
            case 163:
                break;
            case 164:
                break;
            case 165:
                break;
            case 166:
                break;
            case 167:
                break;
            case 168:
                break;
            case 169:
                break;
            case 170:
                break;
            case 171:
                break;
            case 172:
                break;
            case 173:
                break;
            case 174:
                break;
            case 175:
                break;
            case 176:
                break;
            case 177:
                break;
            case 178:
                break;
            case 179:
                break;
            case 180:
                break;
            case 181:
                break;
            case 182:
                break;
            case 183:
                break;
            case 184:
                break;
            case 185:
                break;
            case 186:
                break;
            case 187:
                break;
            case 188:
                break;
            case 189:
                break;
            case 190:
                break;
            case 191:
                break;
            case 192:
                break;
            case 193:
                break;
            case 194:
                break;
            case 195:
                break;
            case 196:
                break;
            case 197:
                break;
            case 198:
                break;
            case 199:
                break;
            case 200:
                break;
            case 201:
                break;
            case 202:
                break;
            case 203:
                break;
            case 204:
                break;
            case 205:
                break;
            case 206:
                break;
            case 207:
                break;
            case 208:
                break;
            case 209:
                break;
            case 210:
                break;
            case 211:
                break;
            case 212:
                break;
            case 213:
                break;
            case 214:
                break;
            case 215:
                break;
            case 216:
                break;
            case 217:
                break;
            case 218:
                break;
            case 219:
                break;
            case 220:
                break;
            case 221:
                break;
            case 222:
                break;
            case 223:
                break;
            case 224:
                break;
            case 225:
                break;
            case 226:
                break;
            case 227:
                break;
            case 228:
                break;
            case 229:
                break;
            case 230:
                break;
            case 231:
                break;
            case 232:
                break;
            case 233:
                break;
            case 234:
                break;
            case 235:
                break;
            case 236:
                break;
            case 237:
                break;
            case 238:
                break;
            case 239:
                break;
            case 240:
                break;
            case 241:
                break;
            case 242:
                break;
            case 243:
                break;
            case 244:
                break;
            case 245:
                break;
            case 246:
                break;
            case 247:
                break;
            case 248:
                break;
            case 249:
                break;
            case 250:
                break;
            case 251:
                break;
            case 252:
                break;
            case 253:
                break;
            case 254:
                break;
            case 255:
                break;
            case 256:
                break;
            case 257:
                break;
            case 258:
                break;
            case 259:
                break;
            case 260:
                break;
            case 261:
                break;
            case 262:
                break;
            case 263:
                break;
            case 264:
                break;
            case 265:
                break;
            case 266:
                break;
            case 267:
                break;
            case 268:
                break;
            case 269:
                break;
            case 270:
                break;
            case 271:
                break;
            case 272:
                break;
            case 273:
                break;
            case 274:
                break;
            case 275:
                break;
            case 276:
                break;
            case 277:
                break;
            case 278:
                break;
            case 279:
                break;
            case 280:
                break;
            case 281:
                break;
            case 282:
                break;
            case 283:
                break;
            case 284:
                break;
            case 285:
                break;
            case 286:
                break;
            case 287:
                break;
            case 288:
                break;
            case 289:
                break;
            case 290:
                break;
            case 291:
                break;
            case 292:
                break;
            case 293:
                break;
            case 294:
                break;
            case 295:
                break;
            case 296:
                break;
            case 297:
                break;
            case 298:
                break;
            case 299:
                break;
            case 300:
                break;
            case 301:
                break;
            case 302:
                break;
            case 303:
                break;
            case 304:
                break;
            case 305:
                break;
            case 306:
                break;
            case 307:
                break;
            case 308:
                break;
            case 309:
                break;
            case 310:
                break;
            case 311:
                break;
            case 312:
                break;
            case 313:
                break;
            case 314:
                break;
            case 315:
                break;
            case 316:
                break;
            case 317:
                break;
            case 318:
                break;
            case 319:
                break;
            case 320:
                break;
            case 321:
                break;
            case 322:
                break;
            case 323:
                break;
            case 324:
                break;
            case 325:
                break;
            case 326:
                break;
            case 327:
                break;
            case 328:
                break;
            case 329:
                break;
            case 330:
                break;
            case 331:
                break;
            case 332:
                break;
            case 333:
                break;
            case 334:
                break;
            case 335:
                break;
            case 336:
                break;
            case 337:
                break;
            case 338:
                break;
            case 339:
                break;
            case 340:
                break;
            case 341:
                break;
            case 342:
                break;
            case 343:
                break;
            case 344:
                break;
            case 345:
                break;
            case 346:
                break;
            case 347:
                break;
            case 348:
                break;
            case 349:
                break;
            case 350:
                break;
            case 351:
                break;
            case 352:
                break;
            case 353:
                break;
            case 354:
                break;
            case 355:
                break;
            case 356:
                break;
            case 357:
                break;
            case 358:
                break;
            case 359:
                break;
            case 360:
                break;
            case 361:
                break;
            case 362:
                break;
            case 363:
                break;
            case 364:
                break;
            case 365:
                break;
            case 366:
                break;
            case 367:
                break;
            case 368:
                break;
            case 369:
                break;
            case 370:
                break;
            case 371:
                break;
            case 372:
                break;
            case 373:
                break;
            case 374:
                break;
            case 375:
                break;
            case 376:
                break;
            case 377:
                break;
            case 378:
                break;
            case 379:
                break;
            case 380:
                break;
            case 381:
                break;
            case 382:
                break;
            case 383:
                break;
            case 384:
                break;
            case 385:
                break;
            case 386:
                break;
            case 387:
                break;
            case 388:
                break;
            case 389:
                break;
            case 390:
                break;
            case 391:
                break;
            case 392:
                break;
            case 393:
                break;
            case 394:
                break;
            case 395:
                break;
            case 396:
                break;
            case 397:
                break;
            case 398:
                break;
            case 399:
                break;
            case 400:
                break;
            case 401:
                break;
            case 402:
                break;
            case 403:
                break;
            case 404:
                break;
            case 405:
                break;
            case 406:
                break;
            case 407:
                break;
            case 408:
                break;
            case 409:
                break;
            case 410:
                break;
            case 411:
                break;
            case 412:
                break;
            case 413:
                break;
            case 414:
                break;
            case 415:
                break;
            case 416:
                break;
            case 417:
                break;
            case 418:
                break;
            case 419:
                break;
            case 420:
                break;
            case 421:
                break;
            case 422:
                break;
            case 423:
                break;
            case 424:
                break;
            case 425:
                break;
            case 426:
                break;
            case 427:
                break;
            case 428:
                break;
            case 429:
                break;
            case 430:
                break;
            case 431:
                break;
            case 432:
                break;
            case 433:
                break;
            case 434:
                break;
            case 435:
                break;
            case 436:
                break;
            case 437:
                break;
            case 438:
                break;
            case 439:
                break;
            case 440:
                break;
            case 441:
                break;
            case 442:
                break;
            case 443:
                break;
            case 444:
                break;
            case 445:
                break;
            case 446:
                break;
            case 447:
                break;
            case 448:
                break;
            case 449:
                break;
            case 450:
                break;
            case 451:
                break;
            case 452:
                break;
            case 453:
                break;
            case 454:
                break;
            case 455:
                break;
            case 456:
                break;
            case 457:
                break;
            case 458:
                break;
            case 459:
                break;
            case 460:
                break;
            case 461:
                break;
            case 462:
                break;
            case 463:
                break;
            case 464:
                break;
            case 465:
                break;
            case 466:
                break;
            case 467:
                break;
            case 468:
                break;
            case 469:
                break;
            case 470:
                break;
            case 471:
                break;
            case 472:
                break;
            case 473:
                break;
            case 474:
                break;
            case 475:
                break;
            case 476:
                break;
            case 477:
                break;
            case 478:
                break;
            case 479:
                break;
            case 480:
                break;
            case 481:
                break;
            case 482:
                break;
            case 483:
                break;
            case 484:
                break;
            case 485:
                break;
            case 486:
                break;
            case 487:
                break;
            case 488:
                break;
            case 489:
                break;
            case 490:
                break;
            case 491:
                break;
            case 492:
                break;
            case 493:
                break;
            case 494:
                break;
            case 495:
                break;
            case 496:
                break;
            case 497:
                break;
            case 498:
                break;
            case 499:
                break;
            case 500:
                break;
            case 501:
                break;
            case 502:
                break;
            case 503:
                break;
            case 504:
                break;
            case 505:
                break;
            case 506:
                break;
            case 507:
                break;
            case 508:
                break;
            case 509:
                break;
            case 510:
                break;
            case 511:
                break;
            case 512:
                break;
            case 513:
                break;
            case 514:
                break;
            case 515:
                break;
            case 516:
                break;
            case 517:
                break;
            case 518:
                break;
            case 519:
                break;
            case 520:
                break;
            case 521:
                break;
            case 522:
                break;
            case 523:
                break;
            case 524:
                break;
            case 525:
                break;
            case 526:
                break;
            case 527:
                break;
            case 528:
                break;
            case 529:
                break;
            case 530:
                break;
            case 531:
                break;
            case 532:
                break;
            case 533:
                break;
            case 534:
                break;
            case 535:
                break;
            case 536:
                break;
            case 537:
                break;
            case 538:
                break;
            case 539:
                break;
            case 540:
                break;
            case 541:
                break;
            case 542:
                break;
            case 543:
                break;
            case 544:
                break;
            case 545:
                break;
            case 546:
                break;
            case 547:
                break;
            case 548:
                break;
            case 549:
                break;
            case 550:
                break;
            case 551:
                break;
            case 552:
                break;
            case 553:
                break;
            case 554:
                break;
            case 555:
                break;
            case 556:
                break;
            case 557:
                break;
            case 558:
                break;
            case 559:
                break;
            case 560:
                break;
            case 561:
                break;
            case 562:
                break;
            case 563:
                break;
            case 564:
                break;
            case 565:
                break;
            case 566:
                break;
            case 567:
                break;
            case 568:
                break;
            case 569:
                break;
            case 570:
                break;
            case 571:
                break;
            case 572:
                break;
            case 573:
                break;
            case 574:
                break;
            case 575:
                break;
            case 576:
                break;
            case 577:
                break;
            case 578:
                break;
            case 579:
                break;
            case 580:
                break;
            case 581:
                break;
            case 582:
                break;
            case 583:
                break;
            case 584:
                break;
            case 585:
                break;
            case 586:
                break;
            case 587:
                break;
            case 588:
                break;
            case 589:
                break;
            case 590:
                break;
            case 591:
                break;
            case 592:
                break;
            case 593:
                break;
            case 594:
                break;
            case 595:
                break;
            case 596:
                break;
            case 597:
                break;
            case 598:
                break;
            case 599:
                break;
            case 600:
                break;
            case 601:
                break;
            case 602:
                break;
            case 603:
                break;
            case 604:
                break;
            case 605:
                break;
            case 606:
                break;
            case 607:
                break;
            case 608:
                break;
            case 609:
                break;
            case 610:
                break;
            case 611:
                break;
            case 612:
                break;
            case 613:
                break;
            case 614:
                break;
            case 615:
                break;
            case 616:
                break;
            case 617:
                break;
            case 618:
                break;
            case 619:
                break;
            case 620:
                break;
            case 621:
                break;
            case 622:
                break;
            case 623:
                break;
            case 624:
                break;
            case 625:
                break;
            case 626:
                break;
            case 627:
                break;
            case 628:
                break;
            case 629:
                break;
            case 630:
                break;
            case 631:
                break;
            case 632:
                break;
            case 633:
                break;
            case 634:
                break;
            case 635:
                break;
            case 636:
                break;
            case 637:
                break;
            case 638:
                break;
            case 639:
                break;
            case 640:
                break;
            case 641:
                break;
            case 642:
                break;
            case 643:
                break;
            case 644:
                break;
            case 645:
                break;
            case 646:
                break;
            case 647:
                break;
            case 648:
                break;
            case 649:
                break;
            case 650:
                break;
            case 651:
                break;
            case 652:
                break;
            case 653:
                break;
            case 654:
                break;
            case 655:
                break;
            case 656:
                break;
            case 657:
                break;
            case 658:
                break;
            case 659:
                break;
            case 660:
                break;
            case 661:
                break;
            case 662:
                break;
            case 663:
                break;
            case 664:
                break;
            case 665:
                break;
            case 666:
                break;
            case 667:
                break;
            case 668:
                break;
            case 669:
                break;
            case 670:
                break;
            case 671:
                break;
            case 672:
                break;
            case 673:
                break;
            case 674:
                break;
            case 675:
                break;
            case 676:
                break;
            case 677:
                break;
            case 678:
                break;
            case 679:
                break;
            case 680:
                break;
            case 681:
                break;
            case 682:
                break;
            case 683:
                break;
            case 684:
                break;
            case 685:
                break;
            case 686:
                break;
            case 687:
                break;
            case 688:
                break;
            case 689:
                break;
            case 690:
                break;
            case 691:
                break;
            case 692:
                break;
            case 693:
                break;
            case 694:
                break;
            case 695:
                break;
            case 696:
                break;
            case 697:
                break;
            case 698:
                break;
            case 699:
                break;
            case 700:
                break;
            case 701:
                break;
            case 702:
                break;
            case 703:
                break;
            case 704:
                break;
            case 705:
                break;
            case 706:
                break;
            case 707:
                break;
            case 708:
                break;
            case 709:
                break;
            case 710:
                break;
            case 711:
                break;
            case 712:
                break;
            case 713:
                break;
            case 714:
                break;
            case 715:
                break;
            case 716:
                break;
            case 717:
                break;
            case 718:
                break;
            case 719:
                break;
            case 720:
                break;
            case 721:
                break;
            case 722:
                break;
            case 723:
                break;
            case 724:
                break;
            case 725:
                break;
            case 726:
                break;
            case 727:
                break;
            case 728:
                break;
            case 729:
                break;
            case 730:
                break;
            case 731:
                break;
            case 732:
                break;
            case 733:
                break;
            case 734:
                break;
            case 735:
                break;
            case 736:
                break;
            case 737:
                break;
            case 738:
                break;
            case 739:
                break;
            case 740:
                break;
            case 741:
                break;
            case 742:
                break;
            case 743:
                break;
            case 744:
                break;
            case 745:
                break;
            case 746:
                break;
            case 747:
                break;
            case 748:
                break;
            case 749:
                break;
            case 750:
                break;
            case 751:
                break;
            case 752:
                break;
            case 753:
                break;
            case 754:
                break;
            case 755:
                break;
            case 756:
                break;
            case 757:
                break;
            case 758:
                break;
            case 759:
                break;
            case 760:
                break;
            case 761:
                break;
            case 762:
                break;
            case 763:
                break;
            case 764:
                break;
            case 765:
                break;
            case 766:
                break;
            case 767:
                break;
            case 768:
                break;
            case 769:
                break;
            case 770:
                break;
            case 771:
                break;
            case 772:
                break;
            case 773:
                break;
            case 774:
                break;
            case 775:
                break;
            case 776:
                break;
            case 777:
                break;
            case 778:
                break;
            case 779:
                break;
            case 780:
                break;
            case 781:
                break;
            case 782:
                break;
            case 783:
                break;
            case 784:
                break;
            case 785:
                break;
            case 786:
                break;
            case 787:
                break;
            case 788:
                break;
            case 789:
                break;
            case 790:
                break;
            case 791:
                break;
            case 792:
                break;
            case 793:
                break;
            case 794:
                break;
            case 795:
                break;
            case 796:
                break;
            case 797:
                break;
            case 798:
                break;
            case 799:
                break;
            case 800:
                break;
            case 801:
                break;
            case 802:
                break;
            case 803:
                break;
            case 804:
                break;
            case 805:
                break;
            case 806:
                break;
            case 807:
                break;
            case 808:
                break;
            case 809:
                break;
            case 810:
                break;
            case 811:
                break;
            case 812:
                break;
            case 813:
                break;
            case 814:
                break;
            case 815:
                break;
            case 816:
                break;
            case 817:
                break;
            case 818:
                break;
            case 819:
                break;
            case 820:
                break;
            case 821:
                break;
            case 822:
                break;
            case 823:
                break;
            case 824:
                break;
            case 825:
                break;
            case 826:
                break;
            case 827:
                break;
            case 828:
                break;
            case 829:
                break;
            case 830:
                break;
            case 831:
                break;
            case 832:
                break;
            case 833:
                break;
            case 834:
                break;
            case 835:
                break;
            case 836:
                break;
            case 837:
                break;
            case 838:
                break;
            case 839:
                break;
            case 840:
                break;
            case 841:
                break;
            case 842:
                break;
            case 843:
                break;
            case 844:
                break;
            case 845:
                break;
            case 846:
                break;
            case 847:
                break;
            case 848:
                break;
            case 849:
                break;
            case 850:
                break;
            case 851:
                break;
            case 852:
                break;
            case 853:
                break;
            case 854:
                break;
            case 855:
                break;
            case 856:
                break;
            case 857:
                break;
            case 858:
                break;
            case 859:
                break;
            case 860:
                break;
            case 861:
                break;
            case 862:
                break;
            case 863:
                break;
            case 864:
                break;
            case 865:
                break;
            case 866:
                break;
            case 867:
                break;
            case 868:
                break;
            case 869:
                break;
            case 870:
                break;
            case 871:
                break;
            case 872:
                break;
            case 873:
                break;
            case 874:
                break;
            case 875:
                break;
            case 876:
                break;
            case 877:
                break;
            case 878:
                break;
            case 879:
                break;
            case 880:
                break;
            case 881:
                break;
            case 882:
                break;
            case 883:
                break;
            case 884:
                break;
            case 885:
                break;
            case 886:
                break;
            case 887:
                break;
            case 888:
                break;
            case 889:
                break;
            case 890:
                break;
            case 891:
                break;
            case 892:
                break;
            case 893:
                break;
            case 894:
                break;
            case 895:
                break;
            case 896:
                break;
            case 897:
                break;
            case 898:
                break;
            case 899:
                break;
            case 900:
                break;
            case 901:
                break;
            case 902:
                break;
            case 903:
                break;
            case 904:
                break;
            case 905:
                break;
            case 906:
                break;
            case 907:
                break;
            case 908:
                break;
            case 909:
                break;
            case 910:
                break;
            case 911:
                break;
            case 912:
                break;
            case 913:
                break;
            case 914:
                break;
            case 915:
                break;
            case 916:
                break;
            case 917:
                break;
            case 918:
                break;
            case 919:
                break;
            case 920:
                break;
            case 921:
                break;
            case 922:
                break;
            case 923:
                break;
            case 924:
                break;
            case 925:
                break;
            case 926:
                break;
            case 927:
                break;
            case 928:
                break;
            case 929:
                break;
            case 930:
                break;
            case 931:
                break;
            case 932:
                break;
            case 933:
                break;
            case 934:
                break;
            case 935:
                break;
            case 936:
                break;
            case 937:
                break;
            case 938:
                break;
            case 939:
                break;
            case 940:
                break;
            case 941:
                break;
            case 942:
                break;
            case 943:
                break;
            case 944:
                break;
            case 945:
                break;
            case 946:
                break;
            case 947:
                break;
            case 948:
                break;
            case 949:
                break;
            case 950:
                break;
            case 951:
                break;
            case 952:
                break;
            case 953:
                break;
            case 954:
                break;
            case 955:
                break;
            case 956:
                break;
            case 957:
                break;
            case 958:
                break;
            case 959:
                break;
            case 960:
                break;
            case 961:
                break;
            case 962:
                break;
            case 963:
                break;
            case 964:
                break;
            case 965:
                break;
            case 966:
                break;
            case 967:
                break;
            case 968:
                break;
            case 969:
                break;
            case 970:
                break;
            case 971:
                break;
            case 972:
                break;
            case 973:
                break;
            case 974:
                break;
            case 975:
                break;
            case 976:
                break;
            case 977:
                break;
            case 978:
                break;
            case 979:
                break;
            case 980:
                break;
            case 981:
                break;
            case 982:
                break;
            case 983:
                break;
            case 984:
                break;
            case 985:
                break;
            case 986:
                break;
            case 987:
                break;
            case 988:
                break;
            case 989:
                break;
            case 990:
                break;
            case 991:
                break;
            case 992:
                break;
            case 993:
                break;
            case 994:
                break;
            case 995:
                break;
            case 996:
                break;
            case 997:
                break;
            case 998:
                break;
            case 999:
                break;
            default:
                break;
        }

    }
    delete[] array_int;
    return 0;
}
