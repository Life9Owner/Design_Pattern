/*Define an object that encapsulates how a set of objects interact.
Mediator promotes loose coupling by keeping objects from 
referring to each other explicitly,
and it lets you vary their interaction independently. */
interface WebServiceMediator {
    // public (1);
    public void buy(double money, WebService service);

    public void SetAmazon(WebService amazon);

    public void SetEbay(WebService ebay);

}

abstract class WebService {
    // protected (2) mediator
    protected WebServiceMediator mediator;

    public abstract void SetMediator(WebServiceMediator mediator);

    // public (3);
    public abstract void buyService(double money);

    public abstract void search(double money);
}

class ConcreteServiceMediator implements WebServiceMediator {
    private WebService amazon;
    private WebService ebay;

    public ConcreteServiceMediator() {
        amazon = null;
        ebay = null;
    }

    public void SetAmazon(WebService amazon) {
        this.amazon = amazon;
    }

    public void SetEbay(WebService ebay) {
        this.ebay = ebay;
    }

    public void buy(double money, WebService service) {
        if (service == amazon) {
            amazon.search(money);
        } else {
            ebay.search(money);
        }
    }
}

class Amazon extends WebService {
    public void SetMediator(WebServiceMediator mediator) {
        this.mediator = mediator;
    }

    public void buyService(double money) {
        // (4);
        this.mediator.buy(money, this);
    }

    public void search(double money) {
        System.out.println("Amazon receive: " + money);
    }
}

class Ebay extends WebService {
    public void SetMediator(WebServiceMediator mediator) {
        this.mediator = mediator;
    }

    public void buyService(double money) {
        // (5);
        this.mediator.buy(money, this);
    }

    public void search(double money) {
        System.out.println("Ebay receive: " + money);
    }
}

public class mediator {

    public static void main(String[] args) {
        // Create a mediator
        WebServiceMediator mediator = new ConcreteServiceMediator();

        // Create specific Web services (Amazon and Ebay)
        WebService amazon = new Amazon();
        WebService ebay = new Ebay();

        // Set the mediator
        amazon.SetMediator(mediator);
        ebay.SetMediator(mediator);

        // Register Web services with the mediator
        mediator.SetAmazon(amazon);
        mediator.SetEbay(ebay);

        // Simulate purchasing services
        double payment1 = 50.0;
        double payment2 = 30.0;

        amazon.buyService(payment1);
        ebay.buyService(payment2);

    }
}