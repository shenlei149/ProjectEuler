using ProjectEuler;
using Xunit;

namespace XUnitTestProjectEuler
{
    [Collection("Collection #01")]
    public class UnitTest01
    {
        [Fact]
        public void Test001To050()
        {
            Assert.Equal("70600674", new S11().GetAnswer());
            Assert.Equal("76576500", new S12().GetAnswer());
            Assert.Equal("837799", new S14().GetAnswer());
            Assert.Equal("871198282", new S22().GetAnswer());
            Assert.Equal("4782", new S25().GetAnswer());
            Assert.Equal("983", new S26().GetAnswer());
            Assert.Equal("-59231", new S27().GetAnswer());
            Assert.Equal("669171001", new S28().GetAnswer());
            Assert.Equal("9183", new S29().GetAnswer());
            Assert.Equal("443839", new S30().GetAnswer());
            Assert.Equal("73682", new S31().GetAnswer());
            Assert.Equal("45228", new S32().GetAnswer());
            Assert.Equal("40730", new S34().GetAnswer());
            Assert.Equal("55", new S35().GetAnswer());
            Assert.Equal("872187", new S36().GetAnswer());
            Assert.Equal("748317", new S37().GetAnswer());
            Assert.Equal("932718654", new S38().GetAnswer());
            Assert.Equal("840", new S39().GetAnswer());
            Assert.Equal("210", new S40().GetAnswer());
            Assert.Equal("7652413", new S41().GetAnswer());
            Assert.Equal("162", new S42().GetAnswer());
            Assert.Equal("16695334890", new S43().GetAnswer());
            Assert.Equal("5482660", new S44().GetAnswer());
            Assert.Equal("1533776805", new S45().GetAnswer());
            Assert.Equal("5777", new S46().GetAnswer());
            Assert.Equal("134043", new S47().GetAnswer());
            Assert.Equal("296962999629", new S49().GetAnswer());
            Assert.Equal("997651", new S50().GetAnswer());
        }
    }

    [Collection("Collection #02")]
    public class UnitTest02
    {
        [Fact]
        public void Test051To100()
        {
            Assert.Equal("121313", new S51().GetAnswer());
            Assert.Equal("142857", new S52().GetAnswer());
            Assert.Equal("376", new S54().GetAnswer());
            Assert.Equal("249", new S55().GetAnswer());
            Assert.Equal("972", new S56().GetAnswer());
            Assert.Equal("153", new S57().GetAnswer());
            Assert.Equal("26241", new S58().GetAnswer());
            Assert.Equal("129448", new S59().GetAnswer());
            Assert.Equal("26033", new S60().GetAnswer()); // ~2.3s
            Assert.Equal("28684", new S61().GetAnswer());
            Assert.Equal("127035954683", new S62().GetAnswer());
            Assert.Equal("1322", new S64().GetAnswer());
            Assert.Equal("272", new S65().GetAnswer());
            Assert.Equal("661", new S66().GetAnswer());
            Assert.Equal("7273", new S67().GetAnswer());
            Assert.Equal("8319823", new S70().GetAnswer()); // ~2s
            Assert.Equal("428570", new S71().GetAnswer());
            Assert.Equal("303963552391", new S72().GetAnswer());
            Assert.Equal("7295372", new S73().GetAnswer());
            Assert.Equal("402", new S74().GetAnswer());
            Assert.Equal("161667", new S75().GetAnswer());
            Assert.Equal("190569291", new S76().GetAnswer());
            Assert.Equal("71", new S77().GetAnswer());
            Assert.Equal("55374", new S78().GetAnswer());
            Assert.Equal("40886", new S80().GetAnswer());
            Assert.Equal("427337", new S81().GetAnswer());
            Assert.Equal("260324", new S82().GetAnswer());
            Assert.Equal("425185", new S83().GetAnswer());
            Assert.Equal("2772", new S85().GetAnswer());
            Assert.Equal("1818", new S86().GetAnswer());
            Assert.Equal("1097343", new S87().GetAnswer());
            Assert.Equal("743", new S89().GetAnswer());
            Assert.Equal("1217", new S90().GetAnswer());
            Assert.Equal("14234", new S91().GetAnswer());
            Assert.Equal("8581146", new S92().GetAnswer());
            Assert.Equal("518408346", new S94().GetAnswer());
            Assert.Equal("14316", new S95().GetAnswer());
            Assert.Equal("24702", new S96().GetAnswer());
            Assert.Equal("8739992577", new S97().GetAnswer());
            Assert.Equal("709", new S99().GetAnswer());
            Assert.Equal("756872327473", new S100().GetAnswer());
        }
    }

    [Collection("Collection #03")]
    public class UnitTest03
    {
        [Fact]
        public void Test101To150()
        {
            Assert.Equal("228", new S102().GetAnswer());
            Assert.Equal("329468", new S104().GetAnswer()); // ~2.5s
            Assert.Equal("180180", new S108().GetAnswer());
            Assert.Equal("9350130049860600", new S110().GetAnswer());
            Assert.Equal("1587000", new S112().GetAnswer());
            Assert.Equal("248155780267521", new S119().GetAnswer());
            Assert.Equal("333082500", new S120().GetAnswer());
            Assert.Equal("21035", new S123().GetAnswer());
            Assert.Equal("21417", new S124().GetAnswer());
            Assert.Equal("2906969179", new S125().GetAnswer());
        }
    }

    [Collection("Collection #04")]
    public class UnitTest04
    {
        [Fact]
        public void Test151To200()
        {
            Assert.Equal("986262", new S179().GetAnswer()); // ~2s
            Assert.Equal("17427258", new S187().GetAnswer()); // ~2s
        }
    }

    [Collection("Collection #05")]
    public class UnitTest05
    {
        [Fact]
        public void Test201To250()
        {
            Assert.Equal("34029210557338", new S203().GetAnswer());
            Assert.Equal("0.5731441", new S205().GetAnswer());
            Assert.Equal("1389019170", new S206().GetAnswer());
            Assert.Equal("892371480", new S243().GetAnswer());
        }
    }

    [Collection("Collection #07")]
    public class UnitTest07
    {
        [Fact]
        public void Test301To350()
        {
            Assert.Equal("2178309", new S301().GetAnswer()); // ~4s
            Assert.Equal("13625242", new S315().GetAnswer());
            Assert.Equal("6.3551758451", new S323().GetAnswer());
            Assert.Equal("199740353/29386561536000", new S329().GetAnswer());
            Assert.Equal("13938", new S345().GetAnswer());
            Assert.Equal("336108797689259276", new S346().GetAnswer());
            Assert.Equal("11109800204052", new S347().GetAnswer()); // ~1.3s
            Assert.Equal("1004195061", new S348().GetAnswer()); // 3.8s
        }
    }

    [Collection("Collection #08")]
    public class UnitTest08
    {
        [Fact]
        public void Test351To400()
        {
            Assert.Equal("1739023853137", new S357().GetAnswer()); //5.5s
            Assert.Equal("139602943319822", new S381().GetAnswer()); // 5.8s
            Assert.Equal("696067597313468", new S387().GetAnswer());
        }
    }

    [Collection("Collection #09")]
    public class UnitTest09
    {
        [Fact]
        public void Test401To450()
        {
            Assert.Equal("98792821", new S429().GetAnswer()); // ~18s
        }
    }

    [Collection("Collection #10")]
    public class UnitTest10
    {
        [Fact]
        public void Test451To500()
        {
            Assert.Equal("194505988824000", new S491().GetAnswer());
            Assert.Equal("6.818741802", new S493().GetAnswer());
            Assert.Equal("35407281", new S500().GetAnswer());
        }
    }

    [Collection("Collection #11")]
    public class UnitTest11
    {
        [Fact]
        public void Test501To550()
        {
            Assert.Equal("694687", new S504().GetAnswer()); // ~4.2s
            Assert.Equal("939087315", new S516().GetAnswer()); // ~2.8s
            Assert.Equal("100315739184392", new S518().GetAnswer()); // 30s, to be optimized
            Assert.Equal("476001479068717", new S549().GetAnswer()); // 19s
        }
    }

    [Collection("Collection #12")]
    public class UnitTest12
    {
        [Fact]
        public void Test551To600()
        {
            Assert.Equal("2240", new S587().GetAnswer());
        }
    }

    [Collection("Collection #13")]
    public class UnitTest13
    {
        [Fact]
        public void Test601To650()
        {
            Assert.Equal("1617243", new S601().GetAnswer());
            Assert.Equal("13.1265108586", new S607().GetAnswer());
            Assert.Equal("0.3916721504", new S613().GetAnswer());
        }
    }

    [Collection("Collection #14")]
    public class UnitTest14
    {
        [Fact]
        public void Test651To700()
        {
            Assert.Equal("922058210", new S684().GetAnswer());
            Assert.Equal("193060223", new S686().GetAnswer());
            Assert.Equal("842043391019219959", new S692().GetAnswer());
            Assert.Equal("1517926517777556", new S700().GetAnswer());
        }
    }

    [Collection("Collection #15")]
    public class UnitTest15
    {
        [Fact]
        public void Test701To750()
        {
            Assert.Equal("128088830547982", new S719().GetAnswer());
        }
    }
}
