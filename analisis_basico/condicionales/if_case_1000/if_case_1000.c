
#include <stdio.h>
#include <stdlib.h>
int readRandomBin(int **array_int, int *num){
    FILE *file = fopen("../random_list.bin", "rb");
    if (file == NULL) {
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *num = file_size / sizeof(int);
    *array_int = (int *)malloc(*num * sizeof(int));

    fread(*array_int, sizeof(int), *num, file);

    fclose(file);
    return 0;
}

int main() {
    int *array_int;
    int num;

    if (readRandomBin(&array_int, &num) != 0){
        printf("Error reading file");
        return 1;
    }

    for (int i = 0; i < num; i++){
        int value = array_int[i] % 1000;
        if (value == 0) {
        } else if (value == 1) {
        } else if (value == 2) {
        } else if (value == 3) {
        } else if (value == 4) {
        } else if (value == 5) {
        } else if (value == 6) {
        } else if (value == 7) {
        } else if (value == 8) {
        } else if (value == 9) {
        } else if (value == 10) {
        } else if (value == 11) {
        } else if (value == 12) {
        } else if (value == 13) {
        } else if (value == 14) {
        } else if (value == 15) {
        } else if (value == 16) {
        } else if (value == 17) {
        } else if (value == 18) {
        } else if (value == 19) {
        } else if (value == 20) {
        } else if (value == 21) {
        } else if (value == 22) {
        } else if (value == 23) {
        } else if (value == 24) {
        } else if (value == 25) {
        } else if (value == 26) {
        } else if (value == 27) {
        } else if (value == 28) {
        } else if (value == 29) {
        } else if (value == 30) {
        } else if (value == 31) {
        } else if (value == 32) {
        } else if (value == 33) {
        } else if (value == 34) {
        } else if (value == 35) {
        } else if (value == 36) {
        } else if (value == 37) {
        } else if (value == 38) {
        } else if (value == 39) {
        } else if (value == 40) {
        } else if (value == 41) {
        } else if (value == 42) {
        } else if (value == 43) {
        } else if (value == 44) {
        } else if (value == 45) {
        } else if (value == 46) {
        } else if (value == 47) {
        } else if (value == 48) {
        } else if (value == 49) {
        } else if (value == 50) {
        } else if (value == 51) {
        } else if (value == 52) {
        } else if (value == 53) {
        } else if (value == 54) {
        } else if (value == 55) {
        } else if (value == 56) {
        } else if (value == 57) {
        } else if (value == 58) {
        } else if (value == 59) {
        } else if (value == 60) {
        } else if (value == 61) {
        } else if (value == 62) {
        } else if (value == 63) {
        } else if (value == 64) {
        } else if (value == 65) {
        } else if (value == 66) {
        } else if (value == 67) {
        } else if (value == 68) {
        } else if (value == 69) {
        } else if (value == 70) {
        } else if (value == 71) {
        } else if (value == 72) {
        } else if (value == 73) {
        } else if (value == 74) {
        } else if (value == 75) {
        } else if (value == 76) {
        } else if (value == 77) {
        } else if (value == 78) {
        } else if (value == 79) {
        } else if (value == 80) {
        } else if (value == 81) {
        } else if (value == 82) {
        } else if (value == 83) {
        } else if (value == 84) {
        } else if (value == 85) {
        } else if (value == 86) {
        } else if (value == 87) {
        } else if (value == 88) {
        } else if (value == 89) {
        } else if (value == 90) {
        } else if (value == 91) {
        } else if (value == 92) {
        } else if (value == 93) {
        } else if (value == 94) {
        } else if (value == 95) {
        } else if (value == 96) {
        } else if (value == 97) {
        } else if (value == 98) {
        } else if (value == 99) {
        } else if (value == 100) {
        } else if (value == 101) {
        } else if (value == 102) {
        } else if (value == 103) {
        } else if (value == 104) {
        } else if (value == 105) {
        } else if (value == 106) {
        } else if (value == 107) {
        } else if (value == 108) {
        } else if (value == 109) {
        } else if (value == 110) {
        } else if (value == 111) {
        } else if (value == 112) {
        } else if (value == 113) {
        } else if (value == 114) {
        } else if (value == 115) {
        } else if (value == 116) {
        } else if (value == 117) {
        } else if (value == 118) {
        } else if (value == 119) {
        } else if (value == 120) {
        } else if (value == 121) {
        } else if (value == 122) {
        } else if (value == 123) {
        } else if (value == 124) {
        } else if (value == 125) {
        } else if (value == 126) {
        } else if (value == 127) {
        } else if (value == 128) {
        } else if (value == 129) {
        } else if (value == 130) {
        } else if (value == 131) {
        } else if (value == 132) {
        } else if (value == 133) {
        } else if (value == 134) {
        } else if (value == 135) {
        } else if (value == 136) {
        } else if (value == 137) {
        } else if (value == 138) {
        } else if (value == 139) {
        } else if (value == 140) {
        } else if (value == 141) {
        } else if (value == 142) {
        } else if (value == 143) {
        } else if (value == 144) {
        } else if (value == 145) {
        } else if (value == 146) {
        } else if (value == 147) {
        } else if (value == 148) {
        } else if (value == 149) {
        } else if (value == 150) {
        } else if (value == 151) {
        } else if (value == 152) {
        } else if (value == 153) {
        } else if (value == 154) {
        } else if (value == 155) {
        } else if (value == 156) {
        } else if (value == 157) {
        } else if (value == 158) {
        } else if (value == 159) {
        } else if (value == 160) {
        } else if (value == 161) {
        } else if (value == 162) {
        } else if (value == 163) {
        } else if (value == 164) {
        } else if (value == 165) {
        } else if (value == 166) {
        } else if (value == 167) {
        } else if (value == 168) {
        } else if (value == 169) {
        } else if (value == 170) {
        } else if (value == 171) {
        } else if (value == 172) {
        } else if (value == 173) {
        } else if (value == 174) {
        } else if (value == 175) {
        } else if (value == 176) {
        } else if (value == 177) {
        } else if (value == 178) {
        } else if (value == 179) {
        } else if (value == 180) {
        } else if (value == 181) {
        } else if (value == 182) {
        } else if (value == 183) {
        } else if (value == 184) {
        } else if (value == 185) {
        } else if (value == 186) {
        } else if (value == 187) {
        } else if (value == 188) {
        } else if (value == 189) {
        } else if (value == 190) {
        } else if (value == 191) {
        } else if (value == 192) {
        } else if (value == 193) {
        } else if (value == 194) {
        } else if (value == 195) {
        } else if (value == 196) {
        } else if (value == 197) {
        } else if (value == 198) {
        } else if (value == 199) {
        } else if (value == 200) {
        } else if (value == 201) {
        } else if (value == 202) {
        } else if (value == 203) {
        } else if (value == 204) {
        } else if (value == 205) {
        } else if (value == 206) {
        } else if (value == 207) {
        } else if (value == 208) {
        } else if (value == 209) {
        } else if (value == 210) {
        } else if (value == 211) {
        } else if (value == 212) {
        } else if (value == 213) {
        } else if (value == 214) {
        } else if (value == 215) {
        } else if (value == 216) {
        } else if (value == 217) {
        } else if (value == 218) {
        } else if (value == 219) {
        } else if (value == 220) {
        } else if (value == 221) {
        } else if (value == 222) {
        } else if (value == 223) {
        } else if (value == 224) {
        } else if (value == 225) {
        } else if (value == 226) {
        } else if (value == 227) {
        } else if (value == 228) {
        } else if (value == 229) {
        } else if (value == 230) {
        } else if (value == 231) {
        } else if (value == 232) {
        } else if (value == 233) {
        } else if (value == 234) {
        } else if (value == 235) {
        } else if (value == 236) {
        } else if (value == 237) {
        } else if (value == 238) {
        } else if (value == 239) {
        } else if (value == 240) {
        } else if (value == 241) {
        } else if (value == 242) {
        } else if (value == 243) {
        } else if (value == 244) {
        } else if (value == 245) {
        } else if (value == 246) {
        } else if (value == 247) {
        } else if (value == 248) {
        } else if (value == 249) {
        } else if (value == 250) {
        } else if (value == 251) {
        } else if (value == 252) {
        } else if (value == 253) {
        } else if (value == 254) {
        } else if (value == 255) {
        } else if (value == 256) {
        } else if (value == 257) {
        } else if (value == 258) {
        } else if (value == 259) {
        } else if (value == 260) {
        } else if (value == 261) {
        } else if (value == 262) {
        } else if (value == 263) {
        } else if (value == 264) {
        } else if (value == 265) {
        } else if (value == 266) {
        } else if (value == 267) {
        } else if (value == 268) {
        } else if (value == 269) {
        } else if (value == 270) {
        } else if (value == 271) {
        } else if (value == 272) {
        } else if (value == 273) {
        } else if (value == 274) {
        } else if (value == 275) {
        } else if (value == 276) {
        } else if (value == 277) {
        } else if (value == 278) {
        } else if (value == 279) {
        } else if (value == 280) {
        } else if (value == 281) {
        } else if (value == 282) {
        } else if (value == 283) {
        } else if (value == 284) {
        } else if (value == 285) {
        } else if (value == 286) {
        } else if (value == 287) {
        } else if (value == 288) {
        } else if (value == 289) {
        } else if (value == 290) {
        } else if (value == 291) {
        } else if (value == 292) {
        } else if (value == 293) {
        } else if (value == 294) {
        } else if (value == 295) {
        } else if (value == 296) {
        } else if (value == 297) {
        } else if (value == 298) {
        } else if (value == 299) {
        } else if (value == 300) {
        } else if (value == 301) {
        } else if (value == 302) {
        } else if (value == 303) {
        } else if (value == 304) {
        } else if (value == 305) {
        } else if (value == 306) {
        } else if (value == 307) {
        } else if (value == 308) {
        } else if (value == 309) {
        } else if (value == 310) {
        } else if (value == 311) {
        } else if (value == 312) {
        } else if (value == 313) {
        } else if (value == 314) {
        } else if (value == 315) {
        } else if (value == 316) {
        } else if (value == 317) {
        } else if (value == 318) {
        } else if (value == 319) {
        } else if (value == 320) {
        } else if (value == 321) {
        } else if (value == 322) {
        } else if (value == 323) {
        } else if (value == 324) {
        } else if (value == 325) {
        } else if (value == 326) {
        } else if (value == 327) {
        } else if (value == 328) {
        } else if (value == 329) {
        } else if (value == 330) {
        } else if (value == 331) {
        } else if (value == 332) {
        } else if (value == 333) {
        } else if (value == 334) {
        } else if (value == 335) {
        } else if (value == 336) {
        } else if (value == 337) {
        } else if (value == 338) {
        } else if (value == 339) {
        } else if (value == 340) {
        } else if (value == 341) {
        } else if (value == 342) {
        } else if (value == 343) {
        } else if (value == 344) {
        } else if (value == 345) {
        } else if (value == 346) {
        } else if (value == 347) {
        } else if (value == 348) {
        } else if (value == 349) {
        } else if (value == 350) {
        } else if (value == 351) {
        } else if (value == 352) {
        } else if (value == 353) {
        } else if (value == 354) {
        } else if (value == 355) {
        } else if (value == 356) {
        } else if (value == 357) {
        } else if (value == 358) {
        } else if (value == 359) {
        } else if (value == 360) {
        } else if (value == 361) {
        } else if (value == 362) {
        } else if (value == 363) {
        } else if (value == 364) {
        } else if (value == 365) {
        } else if (value == 366) {
        } else if (value == 367) {
        } else if (value == 368) {
        } else if (value == 369) {
        } else if (value == 370) {
        } else if (value == 371) {
        } else if (value == 372) {
        } else if (value == 373) {
        } else if (value == 374) {
        } else if (value == 375) {
        } else if (value == 376) {
        } else if (value == 377) {
        } else if (value == 378) {
        } else if (value == 379) {
        } else if (value == 380) {
        } else if (value == 381) {
        } else if (value == 382) {
        } else if (value == 383) {
        } else if (value == 384) {
        } else if (value == 385) {
        } else if (value == 386) {
        } else if (value == 387) {
        } else if (value == 388) {
        } else if (value == 389) {
        } else if (value == 390) {
        } else if (value == 391) {
        } else if (value == 392) {
        } else if (value == 393) {
        } else if (value == 394) {
        } else if (value == 395) {
        } else if (value == 396) {
        } else if (value == 397) {
        } else if (value == 398) {
        } else if (value == 399) {
        } else if (value == 400) {
        } else if (value == 401) {
        } else if (value == 402) {
        } else if (value == 403) {
        } else if (value == 404) {
        } else if (value == 405) {
        } else if (value == 406) {
        } else if (value == 407) {
        } else if (value == 408) {
        } else if (value == 409) {
        } else if (value == 410) {
        } else if (value == 411) {
        } else if (value == 412) {
        } else if (value == 413) {
        } else if (value == 414) {
        } else if (value == 415) {
        } else if (value == 416) {
        } else if (value == 417) {
        } else if (value == 418) {
        } else if (value == 419) {
        } else if (value == 420) {
        } else if (value == 421) {
        } else if (value == 422) {
        } else if (value == 423) {
        } else if (value == 424) {
        } else if (value == 425) {
        } else if (value == 426) {
        } else if (value == 427) {
        } else if (value == 428) {
        } else if (value == 429) {
        } else if (value == 430) {
        } else if (value == 431) {
        } else if (value == 432) {
        } else if (value == 433) {
        } else if (value == 434) {
        } else if (value == 435) {
        } else if (value == 436) {
        } else if (value == 437) {
        } else if (value == 438) {
        } else if (value == 439) {
        } else if (value == 440) {
        } else if (value == 441) {
        } else if (value == 442) {
        } else if (value == 443) {
        } else if (value == 444) {
        } else if (value == 445) {
        } else if (value == 446) {
        } else if (value == 447) {
        } else if (value == 448) {
        } else if (value == 449) {
        } else if (value == 450) {
        } else if (value == 451) {
        } else if (value == 452) {
        } else if (value == 453) {
        } else if (value == 454) {
        } else if (value == 455) {
        } else if (value == 456) {
        } else if (value == 457) {
        } else if (value == 458) {
        } else if (value == 459) {
        } else if (value == 460) {
        } else if (value == 461) {
        } else if (value == 462) {
        } else if (value == 463) {
        } else if (value == 464) {
        } else if (value == 465) {
        } else if (value == 466) {
        } else if (value == 467) {
        } else if (value == 468) {
        } else if (value == 469) {
        } else if (value == 470) {
        } else if (value == 471) {
        } else if (value == 472) {
        } else if (value == 473) {
        } else if (value == 474) {
        } else if (value == 475) {
        } else if (value == 476) {
        } else if (value == 477) {
        } else if (value == 478) {
        } else if (value == 479) {
        } else if (value == 480) {
        } else if (value == 481) {
        } else if (value == 482) {
        } else if (value == 483) {
        } else if (value == 484) {
        } else if (value == 485) {
        } else if (value == 486) {
        } else if (value == 487) {
        } else if (value == 488) {
        } else if (value == 489) {
        } else if (value == 490) {
        } else if (value == 491) {
        } else if (value == 492) {
        } else if (value == 493) {
        } else if (value == 494) {
        } else if (value == 495) {
        } else if (value == 496) {
        } else if (value == 497) {
        } else if (value == 498) {
        } else if (value == 499) {
        } else if (value == 500) {
        } else if (value == 501) {
        } else if (value == 502) {
        } else if (value == 503) {
        } else if (value == 504) {
        } else if (value == 505) {
        } else if (value == 506) {
        } else if (value == 507) {
        } else if (value == 508) {
        } else if (value == 509) {
        } else if (value == 510) {
        } else if (value == 511) {
        } else if (value == 512) {
        } else if (value == 513) {
        } else if (value == 514) {
        } else if (value == 515) {
        } else if (value == 516) {
        } else if (value == 517) {
        } else if (value == 518) {
        } else if (value == 519) {
        } else if (value == 520) {
        } else if (value == 521) {
        } else if (value == 522) {
        } else if (value == 523) {
        } else if (value == 524) {
        } else if (value == 525) {
        } else if (value == 526) {
        } else if (value == 527) {
        } else if (value == 528) {
        } else if (value == 529) {
        } else if (value == 530) {
        } else if (value == 531) {
        } else if (value == 532) {
        } else if (value == 533) {
        } else if (value == 534) {
        } else if (value == 535) {
        } else if (value == 536) {
        } else if (value == 537) {
        } else if (value == 538) {
        } else if (value == 539) {
        } else if (value == 540) {
        } else if (value == 541) {
        } else if (value == 542) {
        } else if (value == 543) {
        } else if (value == 544) {
        } else if (value == 545) {
        } else if (value == 546) {
        } else if (value == 547) {
        } else if (value == 548) {
        } else if (value == 549) {
        } else if (value == 550) {
        } else if (value == 551) {
        } else if (value == 552) {
        } else if (value == 553) {
        } else if (value == 554) {
        } else if (value == 555) {
        } else if (value == 556) {
        } else if (value == 557) {
        } else if (value == 558) {
        } else if (value == 559) {
        } else if (value == 560) {
        } else if (value == 561) {
        } else if (value == 562) {
        } else if (value == 563) {
        } else if (value == 564) {
        } else if (value == 565) {
        } else if (value == 566) {
        } else if (value == 567) {
        } else if (value == 568) {
        } else if (value == 569) {
        } else if (value == 570) {
        } else if (value == 571) {
        } else if (value == 572) {
        } else if (value == 573) {
        } else if (value == 574) {
        } else if (value == 575) {
        } else if (value == 576) {
        } else if (value == 577) {
        } else if (value == 578) {
        } else if (value == 579) {
        } else if (value == 580) {
        } else if (value == 581) {
        } else if (value == 582) {
        } else if (value == 583) {
        } else if (value == 584) {
        } else if (value == 585) {
        } else if (value == 586) {
        } else if (value == 587) {
        } else if (value == 588) {
        } else if (value == 589) {
        } else if (value == 590) {
        } else if (value == 591) {
        } else if (value == 592) {
        } else if (value == 593) {
        } else if (value == 594) {
        } else if (value == 595) {
        } else if (value == 596) {
        } else if (value == 597) {
        } else if (value == 598) {
        } else if (value == 599) {
        } else if (value == 600) {
        } else if (value == 601) {
        } else if (value == 602) {
        } else if (value == 603) {
        } else if (value == 604) {
        } else if (value == 605) {
        } else if (value == 606) {
        } else if (value == 607) {
        } else if (value == 608) {
        } else if (value == 609) {
        } else if (value == 610) {
        } else if (value == 611) {
        } else if (value == 612) {
        } else if (value == 613) {
        } else if (value == 614) {
        } else if (value == 615) {
        } else if (value == 616) {
        } else if (value == 617) {
        } else if (value == 618) {
        } else if (value == 619) {
        } else if (value == 620) {
        } else if (value == 621) {
        } else if (value == 622) {
        } else if (value == 623) {
        } else if (value == 624) {
        } else if (value == 625) {
        } else if (value == 626) {
        } else if (value == 627) {
        } else if (value == 628) {
        } else if (value == 629) {
        } else if (value == 630) {
        } else if (value == 631) {
        } else if (value == 632) {
        } else if (value == 633) {
        } else if (value == 634) {
        } else if (value == 635) {
        } else if (value == 636) {
        } else if (value == 637) {
        } else if (value == 638) {
        } else if (value == 639) {
        } else if (value == 640) {
        } else if (value == 641) {
        } else if (value == 642) {
        } else if (value == 643) {
        } else if (value == 644) {
        } else if (value == 645) {
        } else if (value == 646) {
        } else if (value == 647) {
        } else if (value == 648) {
        } else if (value == 649) {
        } else if (value == 650) {
        } else if (value == 651) {
        } else if (value == 652) {
        } else if (value == 653) {
        } else if (value == 654) {
        } else if (value == 655) {
        } else if (value == 656) {
        } else if (value == 657) {
        } else if (value == 658) {
        } else if (value == 659) {
        } else if (value == 660) {
        } else if (value == 661) {
        } else if (value == 662) {
        } else if (value == 663) {
        } else if (value == 664) {
        } else if (value == 665) {
        } else if (value == 666) {
        } else if (value == 667) {
        } else if (value == 668) {
        } else if (value == 669) {
        } else if (value == 670) {
        } else if (value == 671) {
        } else if (value == 672) {
        } else if (value == 673) {
        } else if (value == 674) {
        } else if (value == 675) {
        } else if (value == 676) {
        } else if (value == 677) {
        } else if (value == 678) {
        } else if (value == 679) {
        } else if (value == 680) {
        } else if (value == 681) {
        } else if (value == 682) {
        } else if (value == 683) {
        } else if (value == 684) {
        } else if (value == 685) {
        } else if (value == 686) {
        } else if (value == 687) {
        } else if (value == 688) {
        } else if (value == 689) {
        } else if (value == 690) {
        } else if (value == 691) {
        } else if (value == 692) {
        } else if (value == 693) {
        } else if (value == 694) {
        } else if (value == 695) {
        } else if (value == 696) {
        } else if (value == 697) {
        } else if (value == 698) {
        } else if (value == 699) {
        } else if (value == 700) {
        } else if (value == 701) {
        } else if (value == 702) {
        } else if (value == 703) {
        } else if (value == 704) {
        } else if (value == 705) {
        } else if (value == 706) {
        } else if (value == 707) {
        } else if (value == 708) {
        } else if (value == 709) {
        } else if (value == 710) {
        } else if (value == 711) {
        } else if (value == 712) {
        } else if (value == 713) {
        } else if (value == 714) {
        } else if (value == 715) {
        } else if (value == 716) {
        } else if (value == 717) {
        } else if (value == 718) {
        } else if (value == 719) {
        } else if (value == 720) {
        } else if (value == 721) {
        } else if (value == 722) {
        } else if (value == 723) {
        } else if (value == 724) {
        } else if (value == 725) {
        } else if (value == 726) {
        } else if (value == 727) {
        } else if (value == 728) {
        } else if (value == 729) {
        } else if (value == 730) {
        } else if (value == 731) {
        } else if (value == 732) {
        } else if (value == 733) {
        } else if (value == 734) {
        } else if (value == 735) {
        } else if (value == 736) {
        } else if (value == 737) {
        } else if (value == 738) {
        } else if (value == 739) {
        } else if (value == 740) {
        } else if (value == 741) {
        } else if (value == 742) {
        } else if (value == 743) {
        } else if (value == 744) {
        } else if (value == 745) {
        } else if (value == 746) {
        } else if (value == 747) {
        } else if (value == 748) {
        } else if (value == 749) {
        } else if (value == 750) {
        } else if (value == 751) {
        } else if (value == 752) {
        } else if (value == 753) {
        } else if (value == 754) {
        } else if (value == 755) {
        } else if (value == 756) {
        } else if (value == 757) {
        } else if (value == 758) {
        } else if (value == 759) {
        } else if (value == 760) {
        } else if (value == 761) {
        } else if (value == 762) {
        } else if (value == 763) {
        } else if (value == 764) {
        } else if (value == 765) {
        } else if (value == 766) {
        } else if (value == 767) {
        } else if (value == 768) {
        } else if (value == 769) {
        } else if (value == 770) {
        } else if (value == 771) {
        } else if (value == 772) {
        } else if (value == 773) {
        } else if (value == 774) {
        } else if (value == 775) {
        } else if (value == 776) {
        } else if (value == 777) {
        } else if (value == 778) {
        } else if (value == 779) {
        } else if (value == 780) {
        } else if (value == 781) {
        } else if (value == 782) {
        } else if (value == 783) {
        } else if (value == 784) {
        } else if (value == 785) {
        } else if (value == 786) {
        } else if (value == 787) {
        } else if (value == 788) {
        } else if (value == 789) {
        } else if (value == 790) {
        } else if (value == 791) {
        } else if (value == 792) {
        } else if (value == 793) {
        } else if (value == 794) {
        } else if (value == 795) {
        } else if (value == 796) {
        } else if (value == 797) {
        } else if (value == 798) {
        } else if (value == 799) {
        } else if (value == 800) {
        } else if (value == 801) {
        } else if (value == 802) {
        } else if (value == 803) {
        } else if (value == 804) {
        } else if (value == 805) {
        } else if (value == 806) {
        } else if (value == 807) {
        } else if (value == 808) {
        } else if (value == 809) {
        } else if (value == 810) {
        } else if (value == 811) {
        } else if (value == 812) {
        } else if (value == 813) {
        } else if (value == 814) {
        } else if (value == 815) {
        } else if (value == 816) {
        } else if (value == 817) {
        } else if (value == 818) {
        } else if (value == 819) {
        } else if (value == 820) {
        } else if (value == 821) {
        } else if (value == 822) {
        } else if (value == 823) {
        } else if (value == 824) {
        } else if (value == 825) {
        } else if (value == 826) {
        } else if (value == 827) {
        } else if (value == 828) {
        } else if (value == 829) {
        } else if (value == 830) {
        } else if (value == 831) {
        } else if (value == 832) {
        } else if (value == 833) {
        } else if (value == 834) {
        } else if (value == 835) {
        } else if (value == 836) {
        } else if (value == 837) {
        } else if (value == 838) {
        } else if (value == 839) {
        } else if (value == 840) {
        } else if (value == 841) {
        } else if (value == 842) {
        } else if (value == 843) {
        } else if (value == 844) {
        } else if (value == 845) {
        } else if (value == 846) {
        } else if (value == 847) {
        } else if (value == 848) {
        } else if (value == 849) {
        } else if (value == 850) {
        } else if (value == 851) {
        } else if (value == 852) {
        } else if (value == 853) {
        } else if (value == 854) {
        } else if (value == 855) {
        } else if (value == 856) {
        } else if (value == 857) {
        } else if (value == 858) {
        } else if (value == 859) {
        } else if (value == 860) {
        } else if (value == 861) {
        } else if (value == 862) {
        } else if (value == 863) {
        } else if (value == 864) {
        } else if (value == 865) {
        } else if (value == 866) {
        } else if (value == 867) {
        } else if (value == 868) {
        } else if (value == 869) {
        } else if (value == 870) {
        } else if (value == 871) {
        } else if (value == 872) {
        } else if (value == 873) {
        } else if (value == 874) {
        } else if (value == 875) {
        } else if (value == 876) {
        } else if (value == 877) {
        } else if (value == 878) {
        } else if (value == 879) {
        } else if (value == 880) {
        } else if (value == 881) {
        } else if (value == 882) {
        } else if (value == 883) {
        } else if (value == 884) {
        } else if (value == 885) {
        } else if (value == 886) {
        } else if (value == 887) {
        } else if (value == 888) {
        } else if (value == 889) {
        } else if (value == 890) {
        } else if (value == 891) {
        } else if (value == 892) {
        } else if (value == 893) {
        } else if (value == 894) {
        } else if (value == 895) {
        } else if (value == 896) {
        } else if (value == 897) {
        } else if (value == 898) {
        } else if (value == 899) {
        } else if (value == 900) {
        } else if (value == 901) {
        } else if (value == 902) {
        } else if (value == 903) {
        } else if (value == 904) {
        } else if (value == 905) {
        } else if (value == 906) {
        } else if (value == 907) {
        } else if (value == 908) {
        } else if (value == 909) {
        } else if (value == 910) {
        } else if (value == 911) {
        } else if (value == 912) {
        } else if (value == 913) {
        } else if (value == 914) {
        } else if (value == 915) {
        } else if (value == 916) {
        } else if (value == 917) {
        } else if (value == 918) {
        } else if (value == 919) {
        } else if (value == 920) {
        } else if (value == 921) {
        } else if (value == 922) {
        } else if (value == 923) {
        } else if (value == 924) {
        } else if (value == 925) {
        } else if (value == 926) {
        } else if (value == 927) {
        } else if (value == 928) {
        } else if (value == 929) {
        } else if (value == 930) {
        } else if (value == 931) {
        } else if (value == 932) {
        } else if (value == 933) {
        } else if (value == 934) {
        } else if (value == 935) {
        } else if (value == 936) {
        } else if (value == 937) {
        } else if (value == 938) {
        } else if (value == 939) {
        } else if (value == 940) {
        } else if (value == 941) {
        } else if (value == 942) {
        } else if (value == 943) {
        } else if (value == 944) {
        } else if (value == 945) {
        } else if (value == 946) {
        } else if (value == 947) {
        } else if (value == 948) {
        } else if (value == 949) {
        } else if (value == 950) {
        } else if (value == 951) {
        } else if (value == 952) {
        } else if (value == 953) {
        } else if (value == 954) {
        } else if (value == 955) {
        } else if (value == 956) {
        } else if (value == 957) {
        } else if (value == 958) {
        } else if (value == 959) {
        } else if (value == 960) {
        } else if (value == 961) {
        } else if (value == 962) {
        } else if (value == 963) {
        } else if (value == 964) {
        } else if (value == 965) {
        } else if (value == 966) {
        } else if (value == 967) {
        } else if (value == 968) {
        } else if (value == 969) {
        } else if (value == 970) {
        } else if (value == 971) {
        } else if (value == 972) {
        } else if (value == 973) {
        } else if (value == 974) {
        } else if (value == 975) {
        } else if (value == 976) {
        } else if (value == 977) {
        } else if (value == 978) {
        } else if (value == 979) {
        } else if (value == 980) {
        } else if (value == 981) {
        } else if (value == 982) {
        } else if (value == 983) {
        } else if (value == 984) {
        } else if (value == 985) {
        } else if (value == 986) {
        } else if (value == 987) {
        } else if (value == 988) {
        } else if (value == 989) {
        } else if (value == 990) {
        } else if (value == 991) {
        } else if (value == 992) {
        } else if (value == 993) {
        } else if (value == 994) {
        } else if (value == 995) {
        } else if (value == 996) {
        } else if (value == 997) {
        } else if (value == 998) {
        } else if (value == 999) {
        }
    }
    free(array_int);
    return 0;
}
