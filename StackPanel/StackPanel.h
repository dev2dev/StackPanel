//
//  Copyright (c) 2011 Aaron Brethorst
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <UIKit/UIKit.h>

@class StackPanel;
@protocol StackPanelDelegate<NSObject>
@optional
- (void)stackPanel:(StackPanel*)aPanel didSelectView:(UIView*)aView;
@end

@interface StackPanel : UIView <UITableViewDelegate, UITableViewDataSource>
{
	UITableView *tableView;
	NSMutableArray *cells;
	
	id<StackPanelDelegate> delegate;
}
@property(nonatomic,assign) id<StackPanelDelegate> delegate;

// Add
- (void)addStackedView:(UIView*)v;
- (void)addStackedView:(UIView *)v reload:(BOOL)yn;
- (void)addStackedViews:(NSArray*)a;

// Remove
- (void)removeStackedViewAtIndex:(NSInteger)index;
- (void)removeStackedViewAtIndex:(NSInteger)index animation:(UITableViewRowAnimation)rowAnimation;
- (void)removeStackedView:(UIView*)aView;
- (void)removeStackedView:(UIView*)aView animation:(UITableViewRowAnimation)rowAnimation;

- (void)reloadStack;
@end