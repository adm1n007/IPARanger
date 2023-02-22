#import "IPARAppDownloadedCell.h"

@implementation IPARAppDownloadedCell

-(id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    
    if (self) {
        self.baseView = [[UIView alloc] init];
        self.baseView.backgroundColor = UIColor.secondarySystemBackgroundColor;
        self.baseView.clipsToBounds = YES;
        self.baseView.layer.cornerRadius = 12;
        self.baseView.layer.cornerCurve = kCACornerCurveContinuous;
        [self addSubview:self.baseView];
        [self.baseView top:self.topAnchor padding:12];
        [self.baseView leading:self.leadingAnchor padding:20];
        [self.baseView trailing:self.trailingAnchor padding:-20];
        [self.baseView bottom:self.bottomAnchor padding:-5];
        
        self.appImage = [[UIImageView alloc] init];
        self.appImage.contentMode = UIViewContentModeScaleAspectFill;
        self.appImage.layer.cornerRadius = 20;
        self.appImage.clipsToBounds = YES;
        [self.baseView addSubview:self.appImage];
        [self.appImage size:CGSizeMake(40, 40)];
        [self.appImage y:self.baseView.centerYAnchor padding:0];
        [self.appImage leading:self.baseView.leadingAnchor padding:10];
        
        self.appName = [[UILabel alloc] init];
        self.appName.textColor = UIColor.labelColor;
        self.appName.font = [UIFont systemFontOfSize:16 weight:UIFontWeightBold];
        self.appName.textAlignment = NSTextAlignmentLeft;
        [self.baseView addSubview:self.appName];
        
        [self.appName top:self.appImage.topAnchor padding:-6.5];
        [self.appName leading:self.appImage.trailingAnchor padding:15];
        //Fit appname to the size of the cell
        self.appName.translatesAutoresizingMaskIntoConstraints = NO;
        [self.baseView addConstraints:@[
            [self.baseView.trailingAnchor constraintGreaterThanOrEqualToAnchor:self.appName.trailingAnchor constant:10],
            [self.baseView.bottomAnchor constraintGreaterThanOrEqualToAnchor:self.appName.bottomAnchor constant:10]
        ]];
        self.appName.adjustsFontSizeToFitWidth = YES;
        self.appName.minimumScaleFactor = 0.3; // Or any other value between 0 and      
        
        self.appFilename = [[UILabel alloc] init];
        self.appFilename.textColor = UIColor.tertiaryLabelColor;
        self.appFilename.font = [UIFont systemFontOfSize:14 weight:UIFontWeightRegular];
        self.appFilename.textAlignment = NSTextAlignmentLeft;
        [self.baseView addSubview:self.appFilename];
        
        [self.appFilename top:self.appName.bottomAnchor padding:1];
        [self.appFilename leading:self.appImage.trailingAnchor padding:15];
        //Fit bundle to the size of the cell
        self.appFilename.translatesAutoresizingMaskIntoConstraints = NO;
        [self.baseView addConstraints:@[
            [self.baseView.trailingAnchor constraintGreaterThanOrEqualToAnchor:self.appFilename.trailingAnchor constant:10],
            [self.baseView.bottomAnchor constraintGreaterThanOrEqualToAnchor:self.appFilename.bottomAnchor constant:10]
        ]];
        self.appFilename.adjustsFontSizeToFitWidth = YES;
        self.appFilename.minimumScaleFactor = 0.3; // Or any other value between 0 an
        // [self.appFilename trailing:self.timeLabel.leadingAnchor padding:-10];
        
        self.appSize = [[UILabel alloc] init];
        self.appSize.textColor = UIColor.tertiaryLabelColor;
        self.appSize.font = [UIFont systemFontOfSize:14 weight:UIFontWeightRegular];
        self.appSize.textAlignment = NSTextAlignmentLeft;
        [self.baseView addSubview:self.appSize];
        
        [self.appSize top:self.appFilename.bottomAnchor padding:0];
        [self.appSize leading:self.appImage.trailingAnchor padding:15];
        // [self.appSize trailing:self.timeLabel.leadingAnchor padding:-10];      
    }
    
    return self;
}


-(void)prepareForReuse {
    [super prepareForReuse];
    self.appImage.image = nil;
    self.appName.text = nil;
    self.appFilename.text = nil;
    self.appSize.text = nil;
}

@end