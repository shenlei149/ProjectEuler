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
            Assert.Equal("9183", new S29().GetAnswer());
            Assert.Equal("73682", new S31().GetAnswer());
            Assert.Equal("40730", new S34().GetAnswer());
            Assert.Equal("7652413", new S41().GetAnswer());
            Assert.Equal("16695334890", new S43().GetAnswer());
            Assert.Equal("997651", new S50().GetAnswer());
        }
    }

    [Collection("Collection #02")]
    public class UnitTest02
    {
        [Fact]
        public void Test051To100()
        {
            Assert.Equal("142857", new S52().GetAnswer());
            Assert.Equal("972", new S56().GetAnswer());
            Assert.Equal("28684", new S61().GetAnswer());
            Assert.Equal("272", new S65().GetAnswer());
            Assert.Equal("7273", new S67().GetAnswer());
            Assert.Equal("402", new S74().GetAnswer());
            Assert.Equal("40886", new S80().GetAnswer());
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
            Assert.Equal("329468", new S104().GetAnswer());
        }
    }

    [Collection("Collection #04")]
    public class UnitTest04
    {
        [Fact]
        public void Test151To200()
        {
            Assert.Equal("986262", new S179().GetAnswer());
            Assert.Equal("17427258", new S187().GetAnswer());
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
        }
    }

    [Collection("Collection #07")]
    public class UnitTest07
    {
        [Fact]
        public void Test301To350()
        {
            Assert.Equal("1004195061", new S348().GetAnswer());
        }
    }

    [Collection("Collection #08")]
    public class UnitTest08
    {
        [Fact]
        public void Test351To400()
        {
            Assert.Equal("1739023853137", new S357().GetAnswer());
            Assert.Equal("139602943319822", new S381().GetAnswer());
            Assert.Equal("696067597313468", new S387().GetAnswer());
        }
    }

    [Collection("Collection #10")]
    public class UnitTest10
    {
        [Fact]
        public void Test451To500()
        {
            Assert.Equal("6.818741802", new S493().GetAnswer());
        }
    }
}
