#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <iomanip>
#include "ISolution.h"
#include "001-050/S11.h"
#include "001-050/S12.h"
#include "001-050/S14.h"
#include "001-050/S22.h"
#include "001-050/S25.h"
#include "001-050/S26.h"
#include "001-050/S27.h"
#include "001-050/S28.h"
#include "001-050/S29.h"
#include "001-050/S30.h"
#include "001-050/S31.h"
#include "001-050/S32.h"
#include "001-050/S34.h"
#include "001-050/S35.h"
#include "001-050/S36.h"
#include "001-050/S37.h"
#include "001-050/S38.h"
#include "001-050/S39.h"
#include "001-050/S40.h"
#include "001-050/S41.h"
#include "001-050/S42.h"
#include "001-050/S43.h"
#include "001-050/S44.h"
#include "001-050/S45.h"
#include "001-050/S46.h"
#include "001-050/S47.h"
#include "001-050/S49.h"
#include "001-050/S50.h"
#include "051-100/S51.h"
#include "051-100/S52.h"
#include "051-100/S54.h"
#include "051-100/S55.h"
#include "051-100/S56.h"
#include "051-100/S57.h"
#include "051-100/S58.h"
#include "051-100/S59.h"
#include "051-100/S60.h"
#include "051-100/S61.h"
#include "051-100/S62.h"
#include "051-100/S64.h"
#include "051-100/S65.h"
#include "051-100/S66.h"
#include "051-100/S67.h"
#include "051-100/S70.h"
#include "051-100/S71.h"
#include "051-100/S72.h"
#include "051-100/S73.h"
#include "051-100/S74.h"
#include "051-100/S75.h"
#include "051-100/S76.h"
#include "051-100/S77.h"
#include "051-100/S78.h"
#include "051-100/S80.h"
#include "051-100/S81.h"
#include "051-100/S82.h"
#include "051-100/S83.h"
#include "051-100/S84.h"
#include "051-100/S85.h"
#include "051-100/S86.h"
#include "051-100/S87.h"
#include "051-100/S88.h"
#include "051-100/S89.h"
#include "051-100/S90.h"
#include "051-100/S91.h"
#include "051-100/S92.h"
#include "051-100/S93.h"
#include "051-100/S94.h"
#include "051-100/S95.h"
#include "051-100/S96.h"
#include "051-100/S97.h"
#include "051-100/S98.h"
#include "051-100/S99.h"
#include "051-100/S100.h"
#include "101-150/S102.h"
#include "101-150/S104.h"
#include "101-150/S107.h"
#include "101-150/S108.h"
#include "101-150/S109.h"
#include "101-150/S110.h"
#include "101-150/S112.h"
#include "101-150/S113.h"
#include "101-150/S114.h"
#include "101-150/S115.h"
#include "101-150/S116.h"
#include "101-150/S117.h"
#include "101-150/S118.h"
#include "101-150/S119.h"
#include "101-150/S120.h"
#include "101-150/S121.h"
#include "101-150/S123.h"
#include "101-150/S124.h"
#include "101-150/S125.h"
#include "151-200/S173.h"
#include "151-200/S174.h"
#include "151-200/S179.h"
#include "151-200/S187.h"
#include "201-250/S203.h"
#include "201-250/S205.h"
#include "201-250/S206.h"
#include "201-250/S243.h"
#include "301-350/S301.h"
#include "301-350/S315.h"
#include "301-350/S323.h"
#include "301-350/S329.h"
#include "301-350/S345.h"
#include "301-350/S346.h"
#include "301-350/S347.h"
#include "301-350/S348.h"
#include "351-400/S357.h"
#include "351-400/S381.h"
#include "351-400/S387.h"
#include "401-450/S429.h"
#include "451-500/S491.h"
#include "451-500/S493.h"
#include "451-500/S500.h"
#include "501-550/S504.h"
#include "501-550/S516.h"
#include "501-550/S518.h"
#include "501-550/S549.h"
#include "551-600/S587.h"
#include "601-650/S601.h"
#include "601-650/S607.h"
#include "601-650/S613.h"
#include "651-700/S684.h"
#include "651-700/S686.h"
#include "651-700/S692.h"
#include "651-700/S700.h"
#include "701-750/S719.h"
#include "701-750/S745.h"
#include "751-800/S751.h"
#include "751-800/S757.h"
#include "751-800/S788.h"
#include "751-800/S800.h"
#include "801-850/S808.h"
#include "801-850/S816.h"
#include "801-850/S820.h"
#include "851-900/S853.h"
#include "851-900/S872.h"
#include "901-950/S932.h"
#include "901-950/S938.h"
#include "901-950/S961.h"

using namespace ProjectEuler;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <problem_number>" << std::endl;
        return 1;
    }

    int problemId = 0;
    try {
        problemId = std::stoi(argv[1]);
    } catch (...) {
        std::cout << "Invalid problem number." << std::endl;
        return 1;
    }

    std::unique_ptr<ISolution> solver;

    switch (problemId) {
        case 11:
            solver = std::make_unique<S11>();
            break;
        case 12:
            solver = std::make_unique<S12>();
            break;
        case 14:
            solver = std::make_unique<S14>();
            break;
        case 22:
            solver = std::make_unique<S22>();
            break;
        case 25:
            solver = std::make_unique<S25>();
            break;
        case 26:
            solver = std::make_unique<S26>();
            break;
        case 27:
            solver = std::make_unique<S27>();
            break;
        case 28:
            solver = std::make_unique<S28>();
            break;
        case 29:
            solver = std::make_unique<S29>();
            break;
        case 30:
            solver = std::make_unique<S30>();
            break;
        case 31:
            solver = std::make_unique<S31>();
            break;
        case 32:
            solver = std::make_unique<S32>();
            break;
        case 34:
            solver = std::make_unique<S34>();
            break;
        case 35:
            solver = std::make_unique<S35>();
            break;
        case 36:
            solver = std::make_unique<S36>();
            break;
        case 37:
            solver = std::make_unique<S37>();
            break;
        case 38:
            solver = std::make_unique<S38>();
            break;
        case 39:
            solver = std::make_unique<S39>();
            break;
        case 40:
            solver = std::make_unique<S40>();
            break;
        case 41:
            solver = std::make_unique<S41>();
            break;
        case 42:
            solver = std::make_unique<S42>();
            break;
        case 43:
            solver = std::make_unique<S43>();
            break;
        case 44:
            solver = std::make_unique<S44>();
            break;
        case 45:
            solver = std::make_unique<S45>();
            break;
        case 46:
            solver = std::make_unique<S46>();
            break;
        case 47:
            solver = std::make_unique<S47>();
            break;
        case 49:
            solver = std::make_unique<S49>();
            break;
        case 50:
            solver = std::make_unique<S50>();
            break;
        case 51:
            solver = std::make_unique<S51>();
            break;
        case 52:
            solver = std::make_unique<S52>();
            break;
        case 54:
            solver = std::make_unique<S54>();
            break;
        case 55:
            solver = std::make_unique<S55>();
            break;
        case 56:
            solver = std::make_unique<S56>();
            break;
        case 57:
            solver = std::make_unique<S57>();
            break;
        case 58:
            solver = std::make_unique<S58>();
            break;
        case 59:
            solver = std::make_unique<S59>();
            break;
        case 60:
            solver = std::make_unique<S60>();
            break;
        case 61:
            solver = std::make_unique<S61>();
            break;
        case 62:
            solver = std::make_unique<S62>();
            break;
        case 64:
            solver = std::make_unique<S64>();
            break;
        case 65:
            solver = std::make_unique<S65>();
            break;
        case 66:
            solver = std::make_unique<S66>();
            break;
        case 67:
            solver = std::make_unique<S67>();
            break;
        case 70:
            solver = std::make_unique<S70>();
            break;
        case 71:
            solver = std::make_unique<S71>();
            break;
        case 72:
            solver = std::make_unique<S72>();
            break;
        case 73:
            solver = std::make_unique<S73>();
            break;
        case 74:
            solver = std::make_unique<S74>();
            break;
        case 75:
            solver = std::make_unique<S75>();
            break;
        case 76:
            solver = std::make_unique<S76>();
            break;
        case 77:
            solver = std::make_unique<S77>();
            break;
        case 78:
            solver = std::make_unique<S78>();
            break;
        case 80:
            solver = std::make_unique<S80>();
            break;
        case 81:
            solver = std::make_unique<S81>();
            break;
        case 82:
            solver = std::make_unique<S82>();
            break;
        case 83:
            solver = std::make_unique<S83>();
            break;
        case 84:
            solver = std::make_unique<S84>();
            break;
        case 85:
            solver = std::make_unique<S85>();
            break;
        case 86:
            solver = std::make_unique<S86>();
            break;
        case 87:
            solver = std::make_unique<S87>();
            break;
        case 88:
            solver = std::make_unique<S88>();
            break;
        case 89:
            solver = std::make_unique<S89>();
            break;
        case 90:
            solver = std::make_unique<S90>();
            break;
        case 91:
            solver = std::make_unique<S91>();
            break;
        case 92:
            solver = std::make_unique<S92>();
            break;
        case 93:
            solver = std::make_unique<S93>();
            break;
        case 94:
            solver = std::make_unique<S94>();
            break;
        case 95:
            solver = std::make_unique<S95>();
            break;
        case 96:
            solver = std::make_unique<S96>();
            break;
        case 97:
            solver = std::make_unique<S97>();
            break;
        case 98:
            solver = std::make_unique<S98>();
            break;
        case 99:
            solver = std::make_unique<S99>();
            break;
        case 100:
            solver = std::make_unique<S100>();
            break;
        case 102:
            solver = std::make_unique<S102>();
            break;
        case 104:
            solver = std::make_unique<S104>();
            break;
        case 107:
            solver = std::make_unique<S107>();
            break;
        case 108:
            solver = std::make_unique<S108>();
            break;
        case 109:
            solver = std::make_unique<S109>();
            break;
        case 110:
            solver = std::make_unique<S110>();
            break;
        case 112:
            solver = std::make_unique<S112>();
            break;
        case 113:
            solver = std::make_unique<S113>();
            break;
        case 114:
            solver = std::make_unique<S114>();
            break;
        case 115:
            solver = std::make_unique<S115>();
            break;
        case 116:
            solver = std::make_unique<S116>();
            break;
        case 117:
            solver = std::make_unique<S117>();
            break;
        case 118:
            solver = std::make_unique<S118>();
            break;
        case 119:
            solver = std::make_unique<S119>();
            break;
        case 120:
            solver = std::make_unique<S120>();
            break;
        case 121:
            solver = std::make_unique<S121>();
            break;
        case 123:
            solver = std::make_unique<S123>();
            break;
        case 124:
            solver = std::make_unique<S124>();
            break;
        case 125:
            solver = std::make_unique<S125>();
            break;
        case 173:
            solver = std::make_unique<S173>();
            break;
        case 174:
            solver = std::make_unique<S174>();
            break;
        case 179:
            solver = std::make_unique<S179>();
            break;
        case 187:
            solver = std::make_unique<S187>();
            break;
        case 203:
            solver = std::make_unique<S203>();
            break;
        case 205:
            solver = std::make_unique<S205>();
            break;
        case 206:
            solver = std::make_unique<S206>();
            break;
        case 243:
            solver = std::make_unique<S243>();
            break;
        case 301:
            solver = std::make_unique<S301>();
            break;
        case 315:
            solver = std::make_unique<S315>();
            break;
        case 323:
            solver = std::make_unique<S323>();
            break;
        case 329:
            solver = std::make_unique<S329>();
            break;
        case 345:
            solver = std::make_unique<S345>();
            break;
        case 346:
            solver = std::make_unique<S346>();
            break;
        case 347:
            solver = std::make_unique<S347>();
            break;
        case 348:
            solver = std::make_unique<S348>();
            break;
        case 357:
            solver = std::make_unique<S357>();
            break;
        case 381:
            solver = std::make_unique<S381>();
            break;
        case 387:
            solver = std::make_unique<S387>();
            break;
        case 429:
            solver = std::make_unique<S429>();
            break;
        case 491:
            solver = std::make_unique<S491>();
            break;
        case 493:
            solver = std::make_unique<S493>();
            break;
        case 500:
            solver = std::make_unique<S500>();
            break;
        case 504:
            solver = std::make_unique<S504>();
            break;
        case 516:
            solver = std::make_unique<S516>();
            break;
        case 518:
            solver = std::make_unique<S518>();
            break;
        case 549:
            solver = std::make_unique<S549>();
            break;
        case 587:
            solver = std::make_unique<S587>();
            break;
        case 601:
            solver = std::make_unique<S601>();
            break;
        case 607:
            solver = std::make_unique<S607>();
            break;
        case 613:
            solver = std::make_unique<S613>();
            break;
        case 684:
            solver = std::make_unique<S684>();
            break;
        case 686:
            solver = std::make_unique<S686>();
            break;
        case 692:
            solver = std::make_unique<S692>();
            break;
        case 700:
            solver = std::make_unique<S700>();
            break;
        case 719:
            solver = std::make_unique<S719>();
            break;
        case 745:
            solver = std::make_unique<S745>();
            break;
        case 751:
            solver = std::make_unique<S751>();
            break;
        case 757:
            solver = std::make_unique<S757>();
            break;
        case 788:
            solver = std::make_unique<S788>();
            break;
        case 800:
            solver = std::make_unique<S800>();
            break;
        case 808:
            solver = std::make_unique<S808>();
            break;
        case 816:
            solver = std::make_unique<S816>();
            break;
        case 820:
            solver = std::make_unique<S820>();
            break;
        case 853:
            solver = std::make_unique<S853>();
            break;
        case 872:
            solver = std::make_unique<S872>();
            break;
        case 932:
            solver = std::make_unique<S932>();
            break;
        case 938:
            solver = std::make_unique<S938>();
            break;
        case 961:
            solver = std::make_unique<S961>();
            break;
        default:
            std::cout << "Problem " << problemId << " not implemented." << std::endl;
            return 1;
    }

    if (solver) {
        auto start = std::chrono::high_resolution_clock::now();
        std::string answer = solver->GetAnswer();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Answer: " << answer << std::endl;
        std::cout << "Time: " << std::fixed << std::setprecision(2) << elapsed.count() << " ms" << std::endl;
    }

    return 0;
}
