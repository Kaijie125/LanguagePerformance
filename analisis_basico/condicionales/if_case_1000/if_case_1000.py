
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
        if value == 0:
            pass
        elif value == 1:
            pass
        elif value == 2:
            pass
        elif value == 3:
            pass
        elif value == 4:
            pass
        elif value == 5:
            pass
        elif value == 6:
            pass
        elif value == 7:
            pass
        elif value == 8:
            pass
        elif value == 9:
            pass
        elif value == 10:
            pass
        elif value == 11:
            pass
        elif value == 12:
            pass
        elif value == 13:
            pass
        elif value == 14:
            pass
        elif value == 15:
            pass
        elif value == 16:
            pass
        elif value == 17:
            pass
        elif value == 18:
            pass
        elif value == 19:
            pass
        elif value == 20:
            pass
        elif value == 21:
            pass
        elif value == 22:
            pass
        elif value == 23:
            pass
        elif value == 24:
            pass
        elif value == 25:
            pass
        elif value == 26:
            pass
        elif value == 27:
            pass
        elif value == 28:
            pass
        elif value == 29:
            pass
        elif value == 30:
            pass
        elif value == 31:
            pass
        elif value == 32:
            pass
        elif value == 33:
            pass
        elif value == 34:
            pass
        elif value == 35:
            pass
        elif value == 36:
            pass
        elif value == 37:
            pass
        elif value == 38:
            pass
        elif value == 39:
            pass
        elif value == 40:
            pass
        elif value == 41:
            pass
        elif value == 42:
            pass
        elif value == 43:
            pass
        elif value == 44:
            pass
        elif value == 45:
            pass
        elif value == 46:
            pass
        elif value == 47:
            pass
        elif value == 48:
            pass
        elif value == 49:
            pass
        elif value == 50:
            pass
        elif value == 51:
            pass
        elif value == 52:
            pass
        elif value == 53:
            pass
        elif value == 54:
            pass
        elif value == 55:
            pass
        elif value == 56:
            pass
        elif value == 57:
            pass
        elif value == 58:
            pass
        elif value == 59:
            pass
        elif value == 60:
            pass
        elif value == 61:
            pass
        elif value == 62:
            pass
        elif value == 63:
            pass
        elif value == 64:
            pass
        elif value == 65:
            pass
        elif value == 66:
            pass
        elif value == 67:
            pass
        elif value == 68:
            pass
        elif value == 69:
            pass
        elif value == 70:
            pass
        elif value == 71:
            pass
        elif value == 72:
            pass
        elif value == 73:
            pass
        elif value == 74:
            pass
        elif value == 75:
            pass
        elif value == 76:
            pass
        elif value == 77:
            pass
        elif value == 78:
            pass
        elif value == 79:
            pass
        elif value == 80:
            pass
        elif value == 81:
            pass
        elif value == 82:
            pass
        elif value == 83:
            pass
        elif value == 84:
            pass
        elif value == 85:
            pass
        elif value == 86:
            pass
        elif value == 87:
            pass
        elif value == 88:
            pass
        elif value == 89:
            pass
        elif value == 90:
            pass
        elif value == 91:
            pass
        elif value == 92:
            pass
        elif value == 93:
            pass
        elif value == 94:
            pass
        elif value == 95:
            pass
        elif value == 96:
            pass
        elif value == 97:
            pass
        elif value == 98:
            pass
        elif value == 99:
            pass
        elif value == 100:
            pass
        elif value == 101:
            pass
        elif value == 102:
            pass
        elif value == 103:
            pass
        elif value == 104:
            pass
        elif value == 105:
            pass
        elif value == 106:
            pass
        elif value == 107:
            pass
        elif value == 108:
            pass
        elif value == 109:
            pass
        elif value == 110:
            pass
        elif value == 111:
            pass
        elif value == 112:
            pass
        elif value == 113:
            pass
        elif value == 114:
            pass
        elif value == 115:
            pass
        elif value == 116:
            pass
        elif value == 117:
            pass
        elif value == 118:
            pass
        elif value == 119:
            pass
        elif value == 120:
            pass
        elif value == 121:
            pass
        elif value == 122:
            pass
        elif value == 123:
            pass
        elif value == 124:
            pass
        elif value == 125:
            pass
        elif value == 126:
            pass
        elif value == 127:
            pass
        elif value == 128:
            pass
        elif value == 129:
            pass
        elif value == 130:
            pass
        elif value == 131:
            pass
        elif value == 132:
            pass
        elif value == 133:
            pass
        elif value == 134:
            pass
        elif value == 135:
            pass
        elif value == 136:
            pass
        elif value == 137:
            pass
        elif value == 138:
            pass
        elif value == 139:
            pass
        elif value == 140:
            pass
        elif value == 141:
            pass
        elif value == 142:
            pass
        elif value == 143:
            pass
        elif value == 144:
            pass
        elif value == 145:
            pass
        elif value == 146:
            pass
        elif value == 147:
            pass
        elif value == 148:
            pass
        elif value == 149:
            pass
        elif value == 150:
            pass
        elif value == 151:
            pass
        elif value == 152:
            pass
        elif value == 153:
            pass
        elif value == 154:
            pass
        elif value == 155:
            pass
        elif value == 156:
            pass
        elif value == 157:
            pass
        elif value == 158:
            pass
        elif value == 159:
            pass
        elif value == 160:
            pass
        elif value == 161:
            pass
        elif value == 162:
            pass
        elif value == 163:
            pass
        elif value == 164:
            pass
        elif value == 165:
            pass
        elif value == 166:
            pass
        elif value == 167:
            pass
        elif value == 168:
            pass
        elif value == 169:
            pass
        elif value == 170:
            pass
        elif value == 171:
            pass
        elif value == 172:
            pass
        elif value == 173:
            pass
        elif value == 174:
            pass
        elif value == 175:
            pass
        elif value == 176:
            pass
        elif value == 177:
            pass
        elif value == 178:
            pass
        elif value == 179:
            pass
        elif value == 180:
            pass
        elif value == 181:
            pass
        elif value == 182:
            pass
        elif value == 183:
            pass
        elif value == 184:
            pass
        elif value == 185:
            pass
        elif value == 186:
            pass
        elif value == 187:
            pass
        elif value == 188:
            pass
        elif value == 189:
            pass
        elif value == 190:
            pass
        elif value == 191:
            pass
        elif value == 192:
            pass
        elif value == 193:
            pass
        elif value == 194:
            pass
        elif value == 195:
            pass
        elif value == 196:
            pass
        elif value == 197:
            pass
        elif value == 198:
            pass
        elif value == 199:
            pass
        elif value == 200:
            pass
        elif value == 201:
            pass
        elif value == 202:
            pass
        elif value == 203:
            pass
        elif value == 204:
            pass
        elif value == 205:
            pass
        elif value == 206:
            pass
        elif value == 207:
            pass
        elif value == 208:
            pass
        elif value == 209:
            pass
        elif value == 210:
            pass
        elif value == 211:
            pass
        elif value == 212:
            pass
        elif value == 213:
            pass
        elif value == 214:
            pass
        elif value == 215:
            pass
        elif value == 216:
            pass
        elif value == 217:
            pass
        elif value == 218:
            pass
        elif value == 219:
            pass
        elif value == 220:
            pass
        elif value == 221:
            pass
        elif value == 222:
            pass
        elif value == 223:
            pass
        elif value == 224:
            pass
        elif value == 225:
            pass
        elif value == 226:
            pass
        elif value == 227:
            pass
        elif value == 228:
            pass
        elif value == 229:
            pass
        elif value == 230:
            pass
        elif value == 231:
            pass
        elif value == 232:
            pass
        elif value == 233:
            pass
        elif value == 234:
            pass
        elif value == 235:
            pass
        elif value == 236:
            pass
        elif value == 237:
            pass
        elif value == 238:
            pass
        elif value == 239:
            pass
        elif value == 240:
            pass
        elif value == 241:
            pass
        elif value == 242:
            pass
        elif value == 243:
            pass
        elif value == 244:
            pass
        elif value == 245:
            pass
        elif value == 246:
            pass
        elif value == 247:
            pass
        elif value == 248:
            pass
        elif value == 249:
            pass
        elif value == 250:
            pass
        elif value == 251:
            pass
        elif value == 252:
            pass
        elif value == 253:
            pass
        elif value == 254:
            pass
        elif value == 255:
            pass
        elif value == 256:
            pass
        elif value == 257:
            pass
        elif value == 258:
            pass
        elif value == 259:
            pass
        elif value == 260:
            pass
        elif value == 261:
            pass
        elif value == 262:
            pass
        elif value == 263:
            pass
        elif value == 264:
            pass
        elif value == 265:
            pass
        elif value == 266:
            pass
        elif value == 267:
            pass
        elif value == 268:
            pass
        elif value == 269:
            pass
        elif value == 270:
            pass
        elif value == 271:
            pass
        elif value == 272:
            pass
        elif value == 273:
            pass
        elif value == 274:
            pass
        elif value == 275:
            pass
        elif value == 276:
            pass
        elif value == 277:
            pass
        elif value == 278:
            pass
        elif value == 279:
            pass
        elif value == 280:
            pass
        elif value == 281:
            pass
        elif value == 282:
            pass
        elif value == 283:
            pass
        elif value == 284:
            pass
        elif value == 285:
            pass
        elif value == 286:
            pass
        elif value == 287:
            pass
        elif value == 288:
            pass
        elif value == 289:
            pass
        elif value == 290:
            pass
        elif value == 291:
            pass
        elif value == 292:
            pass
        elif value == 293:
            pass
        elif value == 294:
            pass
        elif value == 295:
            pass
        elif value == 296:
            pass
        elif value == 297:
            pass
        elif value == 298:
            pass
        elif value == 299:
            pass
        elif value == 300:
            pass
        elif value == 301:
            pass
        elif value == 302:
            pass
        elif value == 303:
            pass
        elif value == 304:
            pass
        elif value == 305:
            pass
        elif value == 306:
            pass
        elif value == 307:
            pass
        elif value == 308:
            pass
        elif value == 309:
            pass
        elif value == 310:
            pass
        elif value == 311:
            pass
        elif value == 312:
            pass
        elif value == 313:
            pass
        elif value == 314:
            pass
        elif value == 315:
            pass
        elif value == 316:
            pass
        elif value == 317:
            pass
        elif value == 318:
            pass
        elif value == 319:
            pass
        elif value == 320:
            pass
        elif value == 321:
            pass
        elif value == 322:
            pass
        elif value == 323:
            pass
        elif value == 324:
            pass
        elif value == 325:
            pass
        elif value == 326:
            pass
        elif value == 327:
            pass
        elif value == 328:
            pass
        elif value == 329:
            pass
        elif value == 330:
            pass
        elif value == 331:
            pass
        elif value == 332:
            pass
        elif value == 333:
            pass
        elif value == 334:
            pass
        elif value == 335:
            pass
        elif value == 336:
            pass
        elif value == 337:
            pass
        elif value == 338:
            pass
        elif value == 339:
            pass
        elif value == 340:
            pass
        elif value == 341:
            pass
        elif value == 342:
            pass
        elif value == 343:
            pass
        elif value == 344:
            pass
        elif value == 345:
            pass
        elif value == 346:
            pass
        elif value == 347:
            pass
        elif value == 348:
            pass
        elif value == 349:
            pass
        elif value == 350:
            pass
        elif value == 351:
            pass
        elif value == 352:
            pass
        elif value == 353:
            pass
        elif value == 354:
            pass
        elif value == 355:
            pass
        elif value == 356:
            pass
        elif value == 357:
            pass
        elif value == 358:
            pass
        elif value == 359:
            pass
        elif value == 360:
            pass
        elif value == 361:
            pass
        elif value == 362:
            pass
        elif value == 363:
            pass
        elif value == 364:
            pass
        elif value == 365:
            pass
        elif value == 366:
            pass
        elif value == 367:
            pass
        elif value == 368:
            pass
        elif value == 369:
            pass
        elif value == 370:
            pass
        elif value == 371:
            pass
        elif value == 372:
            pass
        elif value == 373:
            pass
        elif value == 374:
            pass
        elif value == 375:
            pass
        elif value == 376:
            pass
        elif value == 377:
            pass
        elif value == 378:
            pass
        elif value == 379:
            pass
        elif value == 380:
            pass
        elif value == 381:
            pass
        elif value == 382:
            pass
        elif value == 383:
            pass
        elif value == 384:
            pass
        elif value == 385:
            pass
        elif value == 386:
            pass
        elif value == 387:
            pass
        elif value == 388:
            pass
        elif value == 389:
            pass
        elif value == 390:
            pass
        elif value == 391:
            pass
        elif value == 392:
            pass
        elif value == 393:
            pass
        elif value == 394:
            pass
        elif value == 395:
            pass
        elif value == 396:
            pass
        elif value == 397:
            pass
        elif value == 398:
            pass
        elif value == 399:
            pass
        elif value == 400:
            pass
        elif value == 401:
            pass
        elif value == 402:
            pass
        elif value == 403:
            pass
        elif value == 404:
            pass
        elif value == 405:
            pass
        elif value == 406:
            pass
        elif value == 407:
            pass
        elif value == 408:
            pass
        elif value == 409:
            pass
        elif value == 410:
            pass
        elif value == 411:
            pass
        elif value == 412:
            pass
        elif value == 413:
            pass
        elif value == 414:
            pass
        elif value == 415:
            pass
        elif value == 416:
            pass
        elif value == 417:
            pass
        elif value == 418:
            pass
        elif value == 419:
            pass
        elif value == 420:
            pass
        elif value == 421:
            pass
        elif value == 422:
            pass
        elif value == 423:
            pass
        elif value == 424:
            pass
        elif value == 425:
            pass
        elif value == 426:
            pass
        elif value == 427:
            pass
        elif value == 428:
            pass
        elif value == 429:
            pass
        elif value == 430:
            pass
        elif value == 431:
            pass
        elif value == 432:
            pass
        elif value == 433:
            pass
        elif value == 434:
            pass
        elif value == 435:
            pass
        elif value == 436:
            pass
        elif value == 437:
            pass
        elif value == 438:
            pass
        elif value == 439:
            pass
        elif value == 440:
            pass
        elif value == 441:
            pass
        elif value == 442:
            pass
        elif value == 443:
            pass
        elif value == 444:
            pass
        elif value == 445:
            pass
        elif value == 446:
            pass
        elif value == 447:
            pass
        elif value == 448:
            pass
        elif value == 449:
            pass
        elif value == 450:
            pass
        elif value == 451:
            pass
        elif value == 452:
            pass
        elif value == 453:
            pass
        elif value == 454:
            pass
        elif value == 455:
            pass
        elif value == 456:
            pass
        elif value == 457:
            pass
        elif value == 458:
            pass
        elif value == 459:
            pass
        elif value == 460:
            pass
        elif value == 461:
            pass
        elif value == 462:
            pass
        elif value == 463:
            pass
        elif value == 464:
            pass
        elif value == 465:
            pass
        elif value == 466:
            pass
        elif value == 467:
            pass
        elif value == 468:
            pass
        elif value == 469:
            pass
        elif value == 470:
            pass
        elif value == 471:
            pass
        elif value == 472:
            pass
        elif value == 473:
            pass
        elif value == 474:
            pass
        elif value == 475:
            pass
        elif value == 476:
            pass
        elif value == 477:
            pass
        elif value == 478:
            pass
        elif value == 479:
            pass
        elif value == 480:
            pass
        elif value == 481:
            pass
        elif value == 482:
            pass
        elif value == 483:
            pass
        elif value == 484:
            pass
        elif value == 485:
            pass
        elif value == 486:
            pass
        elif value == 487:
            pass
        elif value == 488:
            pass
        elif value == 489:
            pass
        elif value == 490:
            pass
        elif value == 491:
            pass
        elif value == 492:
            pass
        elif value == 493:
            pass
        elif value == 494:
            pass
        elif value == 495:
            pass
        elif value == 496:
            pass
        elif value == 497:
            pass
        elif value == 498:
            pass
        elif value == 499:
            pass
        elif value == 500:
            pass
        elif value == 501:
            pass
        elif value == 502:
            pass
        elif value == 503:
            pass
        elif value == 504:
            pass
        elif value == 505:
            pass
        elif value == 506:
            pass
        elif value == 507:
            pass
        elif value == 508:
            pass
        elif value == 509:
            pass
        elif value == 510:
            pass
        elif value == 511:
            pass
        elif value == 512:
            pass
        elif value == 513:
            pass
        elif value == 514:
            pass
        elif value == 515:
            pass
        elif value == 516:
            pass
        elif value == 517:
            pass
        elif value == 518:
            pass
        elif value == 519:
            pass
        elif value == 520:
            pass
        elif value == 521:
            pass
        elif value == 522:
            pass
        elif value == 523:
            pass
        elif value == 524:
            pass
        elif value == 525:
            pass
        elif value == 526:
            pass
        elif value == 527:
            pass
        elif value == 528:
            pass
        elif value == 529:
            pass
        elif value == 530:
            pass
        elif value == 531:
            pass
        elif value == 532:
            pass
        elif value == 533:
            pass
        elif value == 534:
            pass
        elif value == 535:
            pass
        elif value == 536:
            pass
        elif value == 537:
            pass
        elif value == 538:
            pass
        elif value == 539:
            pass
        elif value == 540:
            pass
        elif value == 541:
            pass
        elif value == 542:
            pass
        elif value == 543:
            pass
        elif value == 544:
            pass
        elif value == 545:
            pass
        elif value == 546:
            pass
        elif value == 547:
            pass
        elif value == 548:
            pass
        elif value == 549:
            pass
        elif value == 550:
            pass
        elif value == 551:
            pass
        elif value == 552:
            pass
        elif value == 553:
            pass
        elif value == 554:
            pass
        elif value == 555:
            pass
        elif value == 556:
            pass
        elif value == 557:
            pass
        elif value == 558:
            pass
        elif value == 559:
            pass
        elif value == 560:
            pass
        elif value == 561:
            pass
        elif value == 562:
            pass
        elif value == 563:
            pass
        elif value == 564:
            pass
        elif value == 565:
            pass
        elif value == 566:
            pass
        elif value == 567:
            pass
        elif value == 568:
            pass
        elif value == 569:
            pass
        elif value == 570:
            pass
        elif value == 571:
            pass
        elif value == 572:
            pass
        elif value == 573:
            pass
        elif value == 574:
            pass
        elif value == 575:
            pass
        elif value == 576:
            pass
        elif value == 577:
            pass
        elif value == 578:
            pass
        elif value == 579:
            pass
        elif value == 580:
            pass
        elif value == 581:
            pass
        elif value == 582:
            pass
        elif value == 583:
            pass
        elif value == 584:
            pass
        elif value == 585:
            pass
        elif value == 586:
            pass
        elif value == 587:
            pass
        elif value == 588:
            pass
        elif value == 589:
            pass
        elif value == 590:
            pass
        elif value == 591:
            pass
        elif value == 592:
            pass
        elif value == 593:
            pass
        elif value == 594:
            pass
        elif value == 595:
            pass
        elif value == 596:
            pass
        elif value == 597:
            pass
        elif value == 598:
            pass
        elif value == 599:
            pass
        elif value == 600:
            pass
        elif value == 601:
            pass
        elif value == 602:
            pass
        elif value == 603:
            pass
        elif value == 604:
            pass
        elif value == 605:
            pass
        elif value == 606:
            pass
        elif value == 607:
            pass
        elif value == 608:
            pass
        elif value == 609:
            pass
        elif value == 610:
            pass
        elif value == 611:
            pass
        elif value == 612:
            pass
        elif value == 613:
            pass
        elif value == 614:
            pass
        elif value == 615:
            pass
        elif value == 616:
            pass
        elif value == 617:
            pass
        elif value == 618:
            pass
        elif value == 619:
            pass
        elif value == 620:
            pass
        elif value == 621:
            pass
        elif value == 622:
            pass
        elif value == 623:
            pass
        elif value == 624:
            pass
        elif value == 625:
            pass
        elif value == 626:
            pass
        elif value == 627:
            pass
        elif value == 628:
            pass
        elif value == 629:
            pass
        elif value == 630:
            pass
        elif value == 631:
            pass
        elif value == 632:
            pass
        elif value == 633:
            pass
        elif value == 634:
            pass
        elif value == 635:
            pass
        elif value == 636:
            pass
        elif value == 637:
            pass
        elif value == 638:
            pass
        elif value == 639:
            pass
        elif value == 640:
            pass
        elif value == 641:
            pass
        elif value == 642:
            pass
        elif value == 643:
            pass
        elif value == 644:
            pass
        elif value == 645:
            pass
        elif value == 646:
            pass
        elif value == 647:
            pass
        elif value == 648:
            pass
        elif value == 649:
            pass
        elif value == 650:
            pass
        elif value == 651:
            pass
        elif value == 652:
            pass
        elif value == 653:
            pass
        elif value == 654:
            pass
        elif value == 655:
            pass
        elif value == 656:
            pass
        elif value == 657:
            pass
        elif value == 658:
            pass
        elif value == 659:
            pass
        elif value == 660:
            pass
        elif value == 661:
            pass
        elif value == 662:
            pass
        elif value == 663:
            pass
        elif value == 664:
            pass
        elif value == 665:
            pass
        elif value == 666:
            pass
        elif value == 667:
            pass
        elif value == 668:
            pass
        elif value == 669:
            pass
        elif value == 670:
            pass
        elif value == 671:
            pass
        elif value == 672:
            pass
        elif value == 673:
            pass
        elif value == 674:
            pass
        elif value == 675:
            pass
        elif value == 676:
            pass
        elif value == 677:
            pass
        elif value == 678:
            pass
        elif value == 679:
            pass
        elif value == 680:
            pass
        elif value == 681:
            pass
        elif value == 682:
            pass
        elif value == 683:
            pass
        elif value == 684:
            pass
        elif value == 685:
            pass
        elif value == 686:
            pass
        elif value == 687:
            pass
        elif value == 688:
            pass
        elif value == 689:
            pass
        elif value == 690:
            pass
        elif value == 691:
            pass
        elif value == 692:
            pass
        elif value == 693:
            pass
        elif value == 694:
            pass
        elif value == 695:
            pass
        elif value == 696:
            pass
        elif value == 697:
            pass
        elif value == 698:
            pass
        elif value == 699:
            pass
        elif value == 700:
            pass
        elif value == 701:
            pass
        elif value == 702:
            pass
        elif value == 703:
            pass
        elif value == 704:
            pass
        elif value == 705:
            pass
        elif value == 706:
            pass
        elif value == 707:
            pass
        elif value == 708:
            pass
        elif value == 709:
            pass
        elif value == 710:
            pass
        elif value == 711:
            pass
        elif value == 712:
            pass
        elif value == 713:
            pass
        elif value == 714:
            pass
        elif value == 715:
            pass
        elif value == 716:
            pass
        elif value == 717:
            pass
        elif value == 718:
            pass
        elif value == 719:
            pass
        elif value == 720:
            pass
        elif value == 721:
            pass
        elif value == 722:
            pass
        elif value == 723:
            pass
        elif value == 724:
            pass
        elif value == 725:
            pass
        elif value == 726:
            pass
        elif value == 727:
            pass
        elif value == 728:
            pass
        elif value == 729:
            pass
        elif value == 730:
            pass
        elif value == 731:
            pass
        elif value == 732:
            pass
        elif value == 733:
            pass
        elif value == 734:
            pass
        elif value == 735:
            pass
        elif value == 736:
            pass
        elif value == 737:
            pass
        elif value == 738:
            pass
        elif value == 739:
            pass
        elif value == 740:
            pass
        elif value == 741:
            pass
        elif value == 742:
            pass
        elif value == 743:
            pass
        elif value == 744:
            pass
        elif value == 745:
            pass
        elif value == 746:
            pass
        elif value == 747:
            pass
        elif value == 748:
            pass
        elif value == 749:
            pass
        elif value == 750:
            pass
        elif value == 751:
            pass
        elif value == 752:
            pass
        elif value == 753:
            pass
        elif value == 754:
            pass
        elif value == 755:
            pass
        elif value == 756:
            pass
        elif value == 757:
            pass
        elif value == 758:
            pass
        elif value == 759:
            pass
        elif value == 760:
            pass
        elif value == 761:
            pass
        elif value == 762:
            pass
        elif value == 763:
            pass
        elif value == 764:
            pass
        elif value == 765:
            pass
        elif value == 766:
            pass
        elif value == 767:
            pass
        elif value == 768:
            pass
        elif value == 769:
            pass
        elif value == 770:
            pass
        elif value == 771:
            pass
        elif value == 772:
            pass
        elif value == 773:
            pass
        elif value == 774:
            pass
        elif value == 775:
            pass
        elif value == 776:
            pass
        elif value == 777:
            pass
        elif value == 778:
            pass
        elif value == 779:
            pass
        elif value == 780:
            pass
        elif value == 781:
            pass
        elif value == 782:
            pass
        elif value == 783:
            pass
        elif value == 784:
            pass
        elif value == 785:
            pass
        elif value == 786:
            pass
        elif value == 787:
            pass
        elif value == 788:
            pass
        elif value == 789:
            pass
        elif value == 790:
            pass
        elif value == 791:
            pass
        elif value == 792:
            pass
        elif value == 793:
            pass
        elif value == 794:
            pass
        elif value == 795:
            pass
        elif value == 796:
            pass
        elif value == 797:
            pass
        elif value == 798:
            pass
        elif value == 799:
            pass
        elif value == 800:
            pass
        elif value == 801:
            pass
        elif value == 802:
            pass
        elif value == 803:
            pass
        elif value == 804:
            pass
        elif value == 805:
            pass
        elif value == 806:
            pass
        elif value == 807:
            pass
        elif value == 808:
            pass
        elif value == 809:
            pass
        elif value == 810:
            pass
        elif value == 811:
            pass
        elif value == 812:
            pass
        elif value == 813:
            pass
        elif value == 814:
            pass
        elif value == 815:
            pass
        elif value == 816:
            pass
        elif value == 817:
            pass
        elif value == 818:
            pass
        elif value == 819:
            pass
        elif value == 820:
            pass
        elif value == 821:
            pass
        elif value == 822:
            pass
        elif value == 823:
            pass
        elif value == 824:
            pass
        elif value == 825:
            pass
        elif value == 826:
            pass
        elif value == 827:
            pass
        elif value == 828:
            pass
        elif value == 829:
            pass
        elif value == 830:
            pass
        elif value == 831:
            pass
        elif value == 832:
            pass
        elif value == 833:
            pass
        elif value == 834:
            pass
        elif value == 835:
            pass
        elif value == 836:
            pass
        elif value == 837:
            pass
        elif value == 838:
            pass
        elif value == 839:
            pass
        elif value == 840:
            pass
        elif value == 841:
            pass
        elif value == 842:
            pass
        elif value == 843:
            pass
        elif value == 844:
            pass
        elif value == 845:
            pass
        elif value == 846:
            pass
        elif value == 847:
            pass
        elif value == 848:
            pass
        elif value == 849:
            pass
        elif value == 850:
            pass
        elif value == 851:
            pass
        elif value == 852:
            pass
        elif value == 853:
            pass
        elif value == 854:
            pass
        elif value == 855:
            pass
        elif value == 856:
            pass
        elif value == 857:
            pass
        elif value == 858:
            pass
        elif value == 859:
            pass
        elif value == 860:
            pass
        elif value == 861:
            pass
        elif value == 862:
            pass
        elif value == 863:
            pass
        elif value == 864:
            pass
        elif value == 865:
            pass
        elif value == 866:
            pass
        elif value == 867:
            pass
        elif value == 868:
            pass
        elif value == 869:
            pass
        elif value == 870:
            pass
        elif value == 871:
            pass
        elif value == 872:
            pass
        elif value == 873:
            pass
        elif value == 874:
            pass
        elif value == 875:
            pass
        elif value == 876:
            pass
        elif value == 877:
            pass
        elif value == 878:
            pass
        elif value == 879:
            pass
        elif value == 880:
            pass
        elif value == 881:
            pass
        elif value == 882:
            pass
        elif value == 883:
            pass
        elif value == 884:
            pass
        elif value == 885:
            pass
        elif value == 886:
            pass
        elif value == 887:
            pass
        elif value == 888:
            pass
        elif value == 889:
            pass
        elif value == 890:
            pass
        elif value == 891:
            pass
        elif value == 892:
            pass
        elif value == 893:
            pass
        elif value == 894:
            pass
        elif value == 895:
            pass
        elif value == 896:
            pass
        elif value == 897:
            pass
        elif value == 898:
            pass
        elif value == 899:
            pass
        elif value == 900:
            pass
        elif value == 901:
            pass
        elif value == 902:
            pass
        elif value == 903:
            pass
        elif value == 904:
            pass
        elif value == 905:
            pass
        elif value == 906:
            pass
        elif value == 907:
            pass
        elif value == 908:
            pass
        elif value == 909:
            pass
        elif value == 910:
            pass
        elif value == 911:
            pass
        elif value == 912:
            pass
        elif value == 913:
            pass
        elif value == 914:
            pass
        elif value == 915:
            pass
        elif value == 916:
            pass
        elif value == 917:
            pass
        elif value == 918:
            pass
        elif value == 919:
            pass
        elif value == 920:
            pass
        elif value == 921:
            pass
        elif value == 922:
            pass
        elif value == 923:
            pass
        elif value == 924:
            pass
        elif value == 925:
            pass
        elif value == 926:
            pass
        elif value == 927:
            pass
        elif value == 928:
            pass
        elif value == 929:
            pass
        elif value == 930:
            pass
        elif value == 931:
            pass
        elif value == 932:
            pass
        elif value == 933:
            pass
        elif value == 934:
            pass
        elif value == 935:
            pass
        elif value == 936:
            pass
        elif value == 937:
            pass
        elif value == 938:
            pass
        elif value == 939:
            pass
        elif value == 940:
            pass
        elif value == 941:
            pass
        elif value == 942:
            pass
        elif value == 943:
            pass
        elif value == 944:
            pass
        elif value == 945:
            pass
        elif value == 946:
            pass
        elif value == 947:
            pass
        elif value == 948:
            pass
        elif value == 949:
            pass
        elif value == 950:
            pass
        elif value == 951:
            pass
        elif value == 952:
            pass
        elif value == 953:
            pass
        elif value == 954:
            pass
        elif value == 955:
            pass
        elif value == 956:
            pass
        elif value == 957:
            pass
        elif value == 958:
            pass
        elif value == 959:
            pass
        elif value == 960:
            pass
        elif value == 961:
            pass
        elif value == 962:
            pass
        elif value == 963:
            pass
        elif value == 964:
            pass
        elif value == 965:
            pass
        elif value == 966:
            pass
        elif value == 967:
            pass
        elif value == 968:
            pass
        elif value == 969:
            pass
        elif value == 970:
            pass
        elif value == 971:
            pass
        elif value == 972:
            pass
        elif value == 973:
            pass
        elif value == 974:
            pass
        elif value == 975:
            pass
        elif value == 976:
            pass
        elif value == 977:
            pass
        elif value == 978:
            pass
        elif value == 979:
            pass
        elif value == 980:
            pass
        elif value == 981:
            pass
        elif value == 982:
            pass
        elif value == 983:
            pass
        elif value == 984:
            pass
        elif value == 985:
            pass
        elif value == 986:
            pass
        elif value == 987:
            pass
        elif value == 988:
            pass
        elif value == 989:
            pass
        elif value == 990:
            pass
        elif value == 991:
            pass
        elif value == 992:
            pass
        elif value == 993:
            pass
        elif value == 994:
            pass
        elif value == 995:
            pass
        elif value == 996:
            pass
        elif value == 997:
            pass
        elif value == 998:
            pass
        elif value == 999:
            pass
