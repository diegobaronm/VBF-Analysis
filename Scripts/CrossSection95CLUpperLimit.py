
import numpy as np
import matplotlib.pyplot as plt
import argparse

def calculate_limit(totalExpected, totalExpectedE, num_toys=30000):
    
    toyExpCollection = []

    for i in range(0,num_toys+1):

        expectedToy = np.random.normal(totalExpected, totalExpectedE)
        if expectedToy < 0:
            expectedToy = 0
        observedToyExp = np.random.poisson(expectedToy)
        
        toyExpCollection.append(observedToyExp)

        
    binNumber = max(toyExpCollection) - min(toyExpCollection)

    histogram = plt.hist(toyExpCollection, bins=binNumber, density=True, alpha=0.7, color='blue', label='Expected events')

    # Add labels and a legend
    plt.xlabel('Number of events',fontsize=18)
    plt.ylabel('Probability Density',fontsize=18)
    plt.title('Expected number of events density (toy experiments)',fontsize=18)
    plt.xticks(fontsize = 15)
    plt.yticks(fontsize = 15)
    plt.xlim(0, 42)

    plt.text(24,0.07,f'{num_toys} Toy Experiments', fontsize=12, color='black')

    pdf = histogram[0]
    CL95 = 0.95*np.sum(pdf)
    limit = 0
    for i in range(0,len(pdf)):
        if np.sum(pdf[0:i])>=CL95:
            limit = histogram[1][i]
            break

    # Add a vertical line
    vertical_line_x = limit  # x-coordinate where you want the vertical line
    plt.axvline(x=vertical_line_x, color='red', linestyle='--', label='95% C.L. = '+str(int(limit))+ ' events')

    plt.legend(fontsize = 14)

    # Show the plot
    plt.savefig('CL95.pdf',bbox_inches='tight')
    plt.show()

    return limit

def get_args():
    parser = argparse.ArgumentParser(description='Calculate 95% CL upper limit using toy experiments.')
    parser.add_argument('totalExpected', type=float, help='Total expected number of events.')
    parser.add_argument('totalExpectedE', type=float, help='Uncertainty on the total expected number of events.')
    parser.add_argument('signalExpected', type=float, help='Expected number of signal events.')
    parser.add_argument('signalExpectedE', type=float, help='Statistical uncertainty on the expected number of signal events.')
    parser.add_argument('systematicUncertaintySignal', type=float, help='Systematic uncertainty on the signal as percent.')
    parser.add_argument('zPeakContamination', type=float, help='Z peak contamination in the signal region as percent.')
    parser.add_argument('--toys', type=int, default=30000, help='Number of toy experiments to run (default: 30000).')
    return parser.parse_args()
        
if __name__ == '__main__':
    args = get_args()

    # Print a reviewof the inputs
    print(f"Total expected events: {args.totalExpected} ± {args.totalExpectedE}")
    print(f"Signal expected events: {args.signalExpected} ± {args.signalExpectedE} (stat) ± {args.signalExpected * (args.systematicUncertaintySignal / 100)} (syst)")
    print(f"Systematic uncertainty on signal: {args.systematicUncertaintySignal}%")
    print(f"Number of toy experiments: {args.toys}")

    # Adjust total expected uncertainty to include systematic uncertainty
    systematic_uncertainty_value = args.signalExpected * (args.systematicUncertaintySignal / 100.0)
    totalExpectedE_with_systematic = np.sqrt(args.totalExpectedE**2 + systematic_uncertainty_value**2)
    print(f"Total expected events: {args.totalExpected} ± {totalExpectedE_with_systematic} (including systematic uncertainty of {args.systematicUncertaintySignal}%)")

    # Calculate the 95% CL upper limit
    upper_limit = calculate_limit(args.totalExpected, totalExpectedE_with_systematic, args.toys)
    print(f"95% CL upper limit on number of events: {int(upper_limit)}")

    # Now, calculate the upper limit on the cross section
    # Adjust signal expected to account for Z peak contamination
    adjusted_signal_expected = args.signalExpected * (1 - args.zPeakContamination / 100.0)
    adjusted_signal_expectedE = totalExpectedE_with_systematic * (1 - args.zPeakContamination / 100.0)
    print(f"Adjusted signal expected events (after Z peak contamination correction): {adjusted_signal_expected} ± {adjusted_signal_expectedE}")

    result = (upper_limit - args.totalExpected + adjusted_signal_expected)/adjusted_signal_expected

    print(f"95% CL upper limit on the cross section (in units of the signal cross section): {result:.2f} times the signal cross section")

